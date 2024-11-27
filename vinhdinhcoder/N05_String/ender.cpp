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

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while(t--) {
        ll x, y;
        char c;
        string s;
        cin >> x >> y >> c;
        cin >> s;
        
        ll n = s.length();
        if(y > x) {
            cout << -1 << "\n";
            continue;
        }
        
        ll ans = INT_MAX;
        for(ll i = 0; i < n; i++) {
            ll dem = 0;
            for(ll j = 0; j < x; j++) {
                if(s[(n - i + j) % n] == c) dem++;
            }
            if(dem >= y) {
                ans = min(ans, i);
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
    
    return 0;
}