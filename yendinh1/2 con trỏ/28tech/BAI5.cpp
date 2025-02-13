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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, sum = 0, res = LLONG_MAX;
    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= x) {
            res = min(res, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    if (res == LLONG_MAX) res = -1; 
    cout << res;
    return 0;
}