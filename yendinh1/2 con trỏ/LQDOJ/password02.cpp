/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;
bool check(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ll so(char c){
    return c-'0';
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    cin >> st;
    ll n = st.size();
    ll res = -1;
    for(ll i = 0; i < n; i++) {
        ll k = 0;
        for(ll j = i; j < n; j++) {
            if(st[j] < '0' || st[j] > '9') break;
            k = k * 10 + so(st[j]);
            if(k >= 100000000) break;
            if(check(k)) {
                res = max(res, k);
            }
        }
    }
    
    cout << res;
    return 0;
}
