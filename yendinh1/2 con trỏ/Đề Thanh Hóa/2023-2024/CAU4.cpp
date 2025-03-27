/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll m, n, sum;
vector<vector<ll>> a;
unordered_map<string, ll> s;
void tinh(ll l, ll r, vector<ll> &b, ll i, ll x, unordered_map<ll, ll> &s) {
    if (i == r) {
        s[x]++;
        return;
    }
    
    for (ll j = 0; j < n; ++j) {
        b[i-l] = a[i][j];
        tinh(l, r, b, i+1, x + a[i][j], s);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> m >> n >> sum;
    a.resize(m);
    for (ll i = 0; i < m; i++){
        a[i].resize(n);
        for (ll j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    ll mid = m / 2;
    unordered_map<ll, ll> l, r;
    vector<ll> s1(mid), s2(m - mid);
    tinh(0, mid, s1, 0, 0, l);
    tinh(mid, m, s2, mid, 0, r);
    ll res = 0;
    for (const auto &k : l) {
        ll l1 = k.fi;
        ll l2 = k.se;
        ll t = sum - l1;
        if (r.count(t)) {
            res += l2 * r[t];
        }
    }
    cout << res << endl;
    return 0;
}