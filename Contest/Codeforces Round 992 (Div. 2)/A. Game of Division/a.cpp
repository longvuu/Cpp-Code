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

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int res = -1;
        for(ll i = 0; i < n && res == -1; i++) {
            bool kt = true;
            for(ll j = 0; j < n && kt; j++) {
                if(i != j && abs(a[i] - a[j]) % k == 0) {
                    kt = false;
                }
            }
            if(kt) {
                res = i + 1;
            }
        }
        
        if(res != -1) {
            cout << "YES\n" << res << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}