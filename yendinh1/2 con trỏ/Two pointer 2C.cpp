/*
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
    vector<ll> a(n + 1);
    vector<ll> s(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i]; 
    }

    ll l = 1, dem = 0;
    for (ll r = 1; r <= n; r++) {
        while (s[r] - s[l - 1] > x && l <= r) {
            l++;
        }
        dem += (r - l + 1);
    }

    cout << dem;
    return 0;
}
