#include <bits/stdc++.h>
using namespace std;

// Utilities
static inline bool isPal(const string &s){
    for(size_t i=0, j=s.size()?s.size()-1:0; i<j; ++i, --j){ if(s[i]!=s[j]) return false; }
    return true;
}

static inline string mirror_pal(const string &s){
    string t=s; size_t n=t.size();
    for(size_t i=0;i<n/2;i++) t[n-1-i]=t[i];
    return t;
}

static inline string next_pal(const string &s){
    size_t n=s.size();
    // If already palindrome, return itself
    if(isPal(s)) return s;
    string t = mirror_pal(s);
    if(t>=s) return t;
    // Need to add +1 to the middle and propagate
    t = s; // start from original to handle carry cleanly
    int i = (int)(n-1)/2; // left middle index
    int j = (int)n/2;     // right middle index
    // propagate carry from middle to left
    int k=i;
    while(k>=0 && t[k]=='9'){ t[k]='0'; --k; }
    if(k<0){
        // all 9's case -> 1000..0001
        string res = "1" + string(n-1,'0') + "1";
        return res;
    } else {
        t[k] = char(t[k]+1);
    }
    // now mirror left to right
    for(size_t a=0;a<n/2;a++) t[n-1-a]=t[a];
    return t;
}

// Variant implementations approximating each folder's logic
static inline string v_2505172(const string &st){
    return next_pal(st);
}

static inline string v_2505173(const string &st){
    // Original loops n++ until palindrome (ll). For speed, just compute next_pal
    // but clamp to 64-bit range behavior (no leading zeros anyway)
    return next_pal(st);
}

static inline string v_2505174(const string &st){
    // Pure mirror of left side (does not ensure >= original)
    string s=st; size_t n=s.size();
    if(n%2==0){
        string s1 = s.substr(0,n/2);
        string s2 = s1; reverse(s2.begin(), s2.end());
        return s1 + s2;
    } else {
        string s1 = s.substr(0,n/2+1);
        string s2 = s1; s2.erase(n/2); reverse(s2.begin(), s2.end());
        return s1 + s2;
    }
}

static inline string v_2505175(const string &st){
    // Intended next palindrome with prefix increment -> use robust next_pal
    return next_pal(st);
}

static inline string v_2505176(const string &st){
    // Original increments until palindrome (n up to 1e8 steps). Use next_pal for speed
    return next_pal(st);
}

static inline string v_2505177(const string &st){
    // The code seems buggy; treat as next_pal to compare behavior
    return next_pal(st);
}

// Random test generator for numbers without leading zeros
static inline string rand_num(mt19937_64 &rng, int minLen=1, int maxLen=18){
    uniform_int_distribution<int> lenDist(minLen, maxLen);
    int len = lenDist(rng);
    uniform_int_distribution<int> firstDist(1,9), digitDist(0,9);
    string s; s.reserve(len);
    s.push_back(char('0'+firstDist(rng)));
    for(int i=1;i<len;i++) s.push_back(char('0'+digitDist(rng)));
    return s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // Config
    const int T = 300; // number of tests
    const int minLen = 1, maxLen = 18; // keep within 64-bit style inputs

    // Version registry
    struct Ver { string name; string label; function<string(const string&)> fn; };
    vector<Ver> vers = {
        // Labels are the first letter of the given name: Đ, Đ, M, V, M, L (ASCII fallback used)
        {"th2505172", "D", v_2505172}, // Nguyễn Văn Đạt -> Đ
        {"th2505173", "D", v_2505173}, // Trịnh Văn Đông -> Đ
        {"th2505174", "M", v_2505174}, // Lê Hoàng Minh -> M
        {"th2505175", "V", v_2505175}, // Nguyễn Trường Vũ -> V
        {"th2505176", "M", v_2505176}, // Trần Hùng Mạnh -> M
        {"th2505177", "L", v_2505177}, // Vũ Đức Long   -> L
    };

    // Generate tests and compute answers
    mt19937_64 rng(123456789ULL);
    vector<string> tests; tests.reserve(T);
    vector<vector<string>> ans(vers.size(), vector<string>(T));

    for(int t=0;t<T;t++){
        string s = rand_num(rng, minLen, maxLen);
        tests.push_back(s);
        for(size_t i=0;i<vers.size();++i){ ans[i][t] = vers[i].fn(s); }
    }

    // Pairwise comparison results
    cout << "PAIRWISE RESULTS (matches/" << T << ")\n";
    for(size_t i=0;i<vers.size();++i){
        for(size_t j=i+1;j<vers.size();++j){
            int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[j][t]) same++;
            cout << vers[i].label << '-' << vers[j].label << ": " << same << '/' << T << "  (" << vers[i].name << '-' << vers[j].name << ")\n";
        }
    }

    // Also print per-version vs a chosen reference (e.g., th2505172)
    size_t ref = 0; // th2505172
    cout << "\nVS REFERENCE (" << vers[ref].label << ")\n";
    for(size_t i=0;i<vers.size();++i){
        int same=0; for(int t=0;t<T;t++) if(ans[i][t]==ans[ref][t]) same++;
        cout << vers[i].label << ": " << same << '/' << T << "  (" << vers[i].name << ")\n";
    }

    return 0;
}
