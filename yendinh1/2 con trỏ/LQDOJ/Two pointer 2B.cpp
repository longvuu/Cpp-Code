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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    vector<ll> s(n+1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    ll l,r,res=LONG_LONG_MAX;
    for (l = 0, r = 0; r < n; r++) {
        while (s[r+1] - s[l] >= x) {
            res = min(res, r-l+1);
            l++;
        }
    }
    cout << res;
    return 0;
}