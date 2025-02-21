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
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<ll> c(m);
    ll j = 0;
    for(ll i = 0; i < m; i++) {
        while(j < n && a[j] < b[i]) j++;
        c[i] = j;
    }
    
    for(ll i = 0; i < m; i++) {
        cout << c[i] << ' ';
    }
    
    return 0;
}