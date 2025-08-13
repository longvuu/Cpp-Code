/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "dpknsna2"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m;
    cin >> m >> n;
    vector<ll> w(n + 1), v(n + 1);
    for (ll i = 1; i <= n; i++) cin >> v[i] >> w[i];
    vector<ll> c(m + 1, 0);
    for (ll i = 1; i <= n; i++) {
        for (ll j = w[i]; j <= m; j++) {
            c[j] = max(c[j], c[j - w[i]] + v[i]);
        }
    }
    cout << c[m] << endl;
    return 0;
}