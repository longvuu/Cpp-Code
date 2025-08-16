/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "dpknste2"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll N = 1e18;    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m;
    cin >> n >> m;
    vector<ll> w, v;
    for (ll i = 1; i <= n; i++) {
        ll s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        for (ll k = 1; s3 > 0; k <<= 1) {
            ll t = min(s3,k);
            w.pb(s1*t);
            v.pb(s2*t);
            s3 -= t;
        }
    }
    vector<ll> c(m + 1, 0);
    for (ll i = 0; i < (ll)w.size(); i++) {
        for (ll j = m; j >= w[i]; j--) {
            c[j] = max(c[j], c[j - w[i]] + v[i]);
        }
    }
    ll res = 0;
    for (ll j = 0; j <= m; j++) {
        res = max(res, c[j]);
    }
    cout << res << endl;
    return 0;
}