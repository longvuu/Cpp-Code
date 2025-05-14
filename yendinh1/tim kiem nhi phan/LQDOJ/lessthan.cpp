/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}
ll lower_bound(vector<pair<ll, ll>> a, ll x) {
    ll l = 0, r = a.size() - 1;
    while (l < r) {
        ll m = (l + r) / 2;
        if (a[m].fi < x) l = m + 1;
        else r = m;
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end());
    vector<ll> res(n);
    for (ll i = 0; i < n; i++) {
        ll cnt = lower_bound(a.begin(), a.end(), make_pair(a[i].fi, 0LL), cmp) - a.begin();
        res[a[i].se] = cnt;
    }
    for (ll i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}