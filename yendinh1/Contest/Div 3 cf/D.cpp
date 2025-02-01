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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool possible = true;
        for(ll i = 0; i < n-1; i++) {
            if(a[i] > a[i+1]) {
                possible = false;
                break;
            }
            ll mn = min(a[i], a[i+1]);
            a[i] -= mn;
            a[i+1] -= mn;
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    
    return 0;
}