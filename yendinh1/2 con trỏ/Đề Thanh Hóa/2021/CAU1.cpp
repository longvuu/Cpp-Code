/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll x, y;
    cin >> x >> y;
    ll g = gcd(x, y);
    vector<ll> a;
    for (ll i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            a.pb(i);
            if (i != g / i) {
                a.pb(g / i);
            }
        }
    }
    cout << a.size();
    return 0;
}