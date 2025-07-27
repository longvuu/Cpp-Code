/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dptick"
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
    vector<ll> t(n+1), r(n+1), f(n+1);
    for(ll i = 1; i <= n; i++) cin >> t[i];
    for(ll i = 1; i <= n-1; i++) cin >> r[i];
    f[0] = 0;
    f[1] = t[1];
    for(ll i = 2; i <= n; i++) {
        f[i] = min(f[i-1] + t[i], f[i-2] + r[i-1]);
    }
    cout << f[n];
    return 0;
}
