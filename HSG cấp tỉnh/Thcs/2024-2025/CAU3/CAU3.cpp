/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
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
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll dem = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 1) {
            dem++;
        }
    }
    ll s = 0, k = 0;
    for (ll i = 0; i < n; ++i) {
        ll t;
        if (a[i] == 1) {
            t = -1;
        } else {
            t = 1;
        }
        k = max(t, k + t);
        s = max(s, k);
    }
    ll res = dem + s;
    if (dem == n) res = n - 1;
    cout << res << endl;

    return 0;
}