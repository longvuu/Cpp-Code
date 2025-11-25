#include <bits/stdc++.h>
using namespace std;

// All versions compute a sequence related to 6*i and formula variants.
// Target correct closed form inferred from majority: 3*n*(n-1)+1 for n>=1.
// Some versions (th2505172, th2505175 sub3) use alternative algebraic expression.
// For n<=1e4, th2505175 & th2505176 use iterative sum of 6*i.
// We'll emulate each version exactly for comparison.

static inline long long v_th2505172(long long n){
    long long d = n + (n*2 - 2)/2 - 1; // as in code
    return (d + n) * (d - n + 1) + d + 1;
}
static inline long long v_th2505173(long long n){ return 3*n*(n-1)+1; }
static inline long long v_th2505174(long long n){ return 3*n*(n-1)+1; }
static inline long long v_th2505175(long long n){
    if(n <= 10000){
        long long res = 1; for(long long i=1;i<n;i++) res += i*6; return res; }
    long long d = n + (n*2 - 2)/2 - 1; return (d + n) * (d - n + 1) + d + 1;
}
static inline long long v_th2505176(long long n){
    if(n <= 10000){ if(n==1) return 1; long long dem=1; for(long long i=1;i<n;i++) dem += i*6; return dem; }
    long long socuoi = (n-1)*6; return (socuoi+6)/2*(n-1)+1; // simplified from code
}
static inline long long v_th2505177(long long n){ return 3*n*(n-1)+1; }

struct Ver{ string name; string label; function<long long(long long)> fn; };

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<Ver> vers = {
        {"th2505172","Đông", v_th2505172},
        {"th2505173","Đạt", v_th2505173},
        {"th2505174","Minh", v_th2505174},
        {"th2505175","Vũ", v_th2505175},
        {"th2505176","Mạnh", v_th2505176},
        {"th2505177","Long", v_th2505177},
    };

    const int T = 300; // number of test n values
    // Generate diverse n including small (edge) and large values
    vector<long long> tests; tests.reserve(T);
    // Deterministic set: 1..50
    for(long long i=1;i<=50 && tests.size()<T;i++) tests.push_back(i);
    // Add powers of 2, multiples of 1000
    for(long long i=1;i<= (1LL<<20) && tests.size()<T; i<<=1) tests.push_back(i);
    for(long long i=0;i<=200000 && tests.size()<T; i+=1000){ if(i>=51) tests.push_back(i); }
    // Fill remainder with random numbers
    mt19937_64 rng(20251114ULL);
    uniform_int_distribution<long long> dist(1, 500000);
    while((int)tests.size()<T) tests.push_back(dist(rng));

    vector<vector<long long>> ans(vers.size(), vector<long long>(T));
    for(size_t i=0;i<vers.size();++i)
        for(int t=0;t<T;t++) ans[i][t]=vers[i].fn(tests[t]);

    cout << "PAIRWISE RESULTS (matches/" << T << ")\n";
    for(size_t i=0;i<vers.size();++i){
        for(size_t j=i+1;j<vers.size();++j){
            int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[j][t]) same++;
            cout << vers[i].label << '-' << vers[j].label << ": " << same << '/' << T
                 << "  (" << vers[i].name << '-' << vers[j].name << ")\n";
        }
    }
    size_t ref=0; cout << "\nVS REFERENCE (" << vers[ref].label << ")\n";
    for(size_t i=0;i<vers.size();++i){ int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[ref][t]) same++; cout<<vers[i].label<<": "<<same<<'/'<<T<<"  ("<<vers[i].name<<")\n"; }

    // Show first 10 test values and outputs for manual inspection
    cout << "\nSAMPLE VALUES (n : outputs by label)\n";
    for(int idx=0; idx<10 && idx<T; ++idx){
        cout << tests[idx] << " : ";
        for(size_t i=0;i<vers.size();++i){ cout << vers[i].label << '=' << ans[i][idx]; if(i+1<vers.size()) cout << ' '; }
        cout << '\n';
    }
    return 0;
}
