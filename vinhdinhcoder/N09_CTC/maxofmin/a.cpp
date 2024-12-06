/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "maxofmin"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

ll GIATRINHONHAT(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll res = 0;
    for(ll i = 0; i <= n-3; i++) {
        ll x = GIATRINHONHAT(a[i], a[i+1], a[i+2]);
        res = max(res, x);
    }
    
    cout << res;
    return 0;
}