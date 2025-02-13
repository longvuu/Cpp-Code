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
    ll n ,m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i =0; i < n; i++) cin >> a[i];
    for(ll i =0; i < m; i++) cin >> b[i];
    ll i = 0, j = 0;
    vector<ll> s(m, 0);
    while (j < m) {
        while (i < n && a[i] < b[j]) {
            i++;
        }
        s[j] = i;
        j++;
    }

    for (ll k = 0; k < m; k++) {
        cout << s[k] << " ";
    }
    return 0;
}