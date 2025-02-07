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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i =0; i < n; i++) cin >> a[i];
    for(ll i =0; i < m; i++) cin >> b[i];
  ll dem = 0, l = 0, r = 0;
  while (l < n && r < m) {
    if (a[l] == b[r]) {
        ll d1 = 1, d2 = 1;
        while (l + d1 < n && a[l] == a[l + d1]) {
            d1++;
        }
        while (r + d2 < m && b[r] == b[r + d2]) {
            d2++;
        }
        dem += d1 * d2;
        l += d1;
        r += d2;
    } else if (a[l] < b[r]) {
        l++;
    } else {
        r++;
    }
}
cout << dem;
return 0;
    cout << dem;
    return 0;
}
