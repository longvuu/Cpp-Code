#include <bits/stdc++.h>
#define taskname "dprentht"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return a.se < b.se;
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end(), cmp);
    ll res = 0, k = 0;
    for (int i = 0; i < n;i++) {
    if (a[i].fi > k) {
        res++;
        k = a[i].se;
    }
    }
    cout << res << endl;
    return 0;
}
