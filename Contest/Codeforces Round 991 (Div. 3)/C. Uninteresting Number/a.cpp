/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

const vector<int> squares = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
inline bool concac(ll digit) {
    return squares[digit] < 10;
}

inline bool check(const string& n, ll mask) {
    ll sum = 0;
    for(size_t j = 0; j < n.length(); j++) {
        ll digit = n[j] - '0';
        sum += (mask & (1ll << j)) ? squares[digit] : digit;
    }
    return sum % 9 == 0;
}

int simp() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        ll len = n.length();
        bool kt = false;

        for(ll i = 0; i < (1ll << len); i++) {
            bool valid = true;
            ll sum = 0;
            for(size_t j = 0; j < len; j++) {
                ll digit = n[j] - '0';
                if(i & (1ll << j)) {
                    if(!concac(digit)) {
                        valid = false;
                        break;
                    }
                    sum += squares[digit];
                } else {
                    sum += digit;
                }
            }
            if(valid && sum % 9 == 0) {
                kt = true;
                break;
            }
        }
        cout << (kt ? "YES" : "NO") << '\n';
    }
    return 0;
}