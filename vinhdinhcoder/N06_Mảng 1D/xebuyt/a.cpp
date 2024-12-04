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
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    
    ll dem = 0, res = 0;
    for(int i = 0; i < n; i++) {
        dem -= a[i].fi;  
        dem += a[i].se;  
        res = max(res, dem);
    }
    
    cout << res;
    return 0;
}