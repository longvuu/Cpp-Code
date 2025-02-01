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
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n+2, 0);
    vector<ll> d(n+2, 0); 
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i-1];
    }
    
    while(q--) {
        ll l,r,k;
        cin >> l >> r >> k;
        l++,r++;
        d[l] += k;    
        d[r+1] -= k;   
    }
    for(ll i = 1; i <= n; i++) {
        a[i] = a[i-1] + d[i];
        cout << a[i] << " ";
    }
    return 0;
}