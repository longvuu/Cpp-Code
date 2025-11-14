#include <bits/stdc++.h>
using namespace std;

// Common helpers
static inline long long minDistTo(const vector<long long>& a, long long x){
    auto it = lower_bound(a.begin(), a.end(), x);
    long long d = LLONG_MAX;
    if(it!=a.end()) d = min(d, llabs(x-*it));
    if(it!=a.begin()){ --it; d = min(d, llabs(x-*it)); }
    return d;
}

// Correct solution: choose x in [l,r] maximizing min distance to any a[i]
// Tie-breaking: choose largest x when distances equal
static inline long long correct_maxdis(vector<long long> a, long long l, long long r){
    sort(a.begin(), a.end());
    long long bestD = -1, ans = l;
    auto relax = [&](long long x){
        if(x<l || x>r) return;
        long long d = minDistTo(a, x);
        if(d > bestD || (d==bestD && x>ans)) ans = x, bestD = d;
    };
    relax(l); relax(r);
    for(size_t i=0;i+1<a.size();++i){
        long long mid = a[i] + (a[i+1]-a[i])/2; // floor midpoint, consistent with many versions
        relax(mid);
        // also try mid+1 to respect tie-to-right when gap is odd
        relax(mid+1);
    }
    return ans;
}

// v_2505172: intended to compute correct answer; mirror with correct algorithm
static inline long long v_2505172(const vector<long long>& a, long long l, long long r){
    return correct_maxdis(a, l, r);
}

// v_2505173: boundary + midpoints logic
static inline long long v_2505173(const vector<long long>& a0, long long l, long long r){
    vector<long long> a=a0; sort(a.begin(), a.end());
    return correct_maxdis(a, l, r);
}

// v_2505174: same approach as correct with floor midpoint
static inline long long v_2505174(const vector<long long>& a0, long long l, long long r){
    vector<long long> a=a0; sort(a.begin(), a.end());
    long long bestD=-1, ans=l;
    auto relax = [&](long long x){
        if(x<l || x>r) return; long long d=minDistTo(a,x);
        if(d>bestD || (d==bestD && x>ans)) { bestD=d; ans=x; }
    };
    relax(l); relax(r);
    for(size_t i=0;i+1<a.size();++i){ long long g = a[i]+(a[i+1]-a[i])/2; relax(g); }
    return ans;
}

// v_2505175: buggy implementation seems to MINIMIZE distance and avoid x==a[i]
static inline long long v_2505175(const vector<long long>& a0, long long l, long long r){
    vector<long long> a=a0; sort(a.begin(), a.end());
    unordered_set<long long> S(a.begin(), a.end());
    long long best = LLONG_MAX, ans = l;
    for(long long x=l;x<=r && x-l<=100000; ++x){ // safety cap for huge ranges
        if(S.count(x)) continue;
        long long d = minDistTo(a,x);
        if(d < best || (d==best && x>ans)) { best=d; ans=x; }
    }
    // If range is huge, approximate by checking some samples
    if(r-l>100000){
        // sample at boundaries and near a[i]
        for(size_t i=0;i<a.size();++i){
            for(long long t=-2;t<=2;t++){
                long long x=a[i]+t; if(x<l||x>r||S.count(x)) continue;
                long long d=minDistTo(a,x);
                if(d < best || (d==best && x>ans)) { best=d; ans=x; }
            }
        }
    }
    return ans;
}

// v_2505176: returns INDEX of array (bug) instead of position; emulate behavior
static inline long long v_2505176(const vector<long long>& a0, long long l, long long r){
    vector<long long> a=a0; // no sort in original
    long long kq=0; long long dem = LLONG_MAX;
    for(long long j=l;j<=r && j-l<=200000; ++j){
        long long res = LLONG_MAX;
        for(size_t i=0;i<a.size(); ++i){
            res = min(res, llabs(j - a[i]));
            if(j==a[i]){ res = LLONG_MAX; break; }
            if(res <= dem){ dem = res; kq = (long long)(i+1); }
        }
    }
    return kq; // index (1-based)
}

// v_2505177: same as 5174 essentially
static inline long long v_2505177(const vector<long long>& a0, long long l, long long r){
    return v_2505174(a0,l,r);
}

// Random test generator
static inline vector<long long> rand_array(mt19937_64 &rng, int n, long long L, long long R){
    uniform_int_distribution<long long> dist(L, R);
    vector<long long> a(n); for(int i=0;i<n;i++) a[i]=dist(rng); return a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    const int T = 300;

    struct Ver { string name; string label; function<long long(const vector<long long>&,long long,long long)> fn; };
    vector<Ver> vers = {
        // Labels = first letter of the given name (ASCII fallback)
        {"th2505172", "Đạt", v_2505172}, // Nguyễn Văn Đạt -> Đ
        {"th2505173", "Đông", v_2505173}, // Trịnh Văn Đông -> Đ
        {"th2505174", "Minh", v_2505174}, // Lê Hoàng Minh -> M
        {"th2505175", "Vũ", v_2505175}, // Nguyễn Trường Vũ -> V
        {"th2505176", "Mạnh", v_2505176}, // Trần Hùng Mạnh -> M
        {"th2505177", "Long", v_2505177}, // Vũ Đức Long   -> L
    };

    mt19937_64 rng(987654321ULL);
    vector<long long> Ls(T), Rs(T); vector<vector<long long>> As(T);

    // generate tests
    uniform_int_distribution<int> nDist(2, 50);
    for(int t=0;t<T;t++){
        // choose l<r within [-1e6,1e6]
        uniform_int_distribution<long long> bdist(-1000000, 1000000);
        long long l = bdist(rng), r = bdist(rng); if(l>r) swap(l,r);
        // avoid too huge loops for buggy versions, cap width
        if(r-l>200000) r = l + 200000;
        int n = nDist(rng);
        auto a = rand_array(rng, n, l-1000, r+1000);
        Ls[t]=l; Rs[t]=r; As[t]=move(a);
    }

    // compute answers
    vector<vector<long long>> ans(vers.size(), vector<long long>(T));
    for(size_t i=0;i<vers.size();++i){
        for(int t=0;t<T;t++) ans[i][t] = vers[i].fn(As[t], Ls[t], Rs[t]);
    }

    // pairwise
    cout << "PAIRWISE RESULTS (matches/" << T << ")\n";
    for(size_t i=0;i<vers.size();++i){
        for(size_t j=i+1;j<vers.size();++j){
            int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[j][t]) same++;
            cout << vers[i].label << '-' << vers[j].label << ": " << same << '/' << T << "  (" << vers[i].name << '-' << vers[j].name << ")\n";
        }
    }

    // vs reference
    size_t ref=0; cout << "\nVS REFERENCE (" << vers[ref].label << ")\n";
    for(size_t i=0;i<vers.size();++i){ int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[ref][t]) same++; cout<<vers[i].label<<": "<<same<<'/'<<T<<"  ("<<vers[i].name<<")\n"; }

    return 0;
}
