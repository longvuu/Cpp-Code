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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n);
    
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0] = a[0];  
    for(ll i = 1; i < n; i++) {
        d[i] = a[i] - a[i-1];  
    }
    
    for(ll i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    
    return 0;
}