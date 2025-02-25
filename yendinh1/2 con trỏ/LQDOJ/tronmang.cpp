/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TRONMANG"
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
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];
    vector<ll> c;
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c.pb(a[i]);
            i++;
        } else {
            c.pb(b[j]);
            j++;
        }
    }
    while (i < n) {
        c.pb(a[i]);
        i++;
    }
    while (j < m) {
        c.pb(b[j]);
        j++;
    }
    for(ll i = 0; i < c.size(); i++) cout << c[i] << " ";
    cout << "\n";
    return 0;
}