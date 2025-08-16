/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "dpknste1"
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
    vector<ll> w(n + 1), v(n + 1);
    for (ll i = 1; i <= n; i++) cin >> w[i] >> v[i];
    ll s = 0;
    for (ll i = 1; i <= n; i++) s += v[i];
    vector<ll> c(s + 1, N);
    c[0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = s; j >= v[i]; j--) {
            if (c[j - v[i]] != N)         
                c[j] = min(c[j], c[j - v[i]] + w[i]);
        }
    }
    ll res = 0;
    for (ll j = s; j >= 0; j--) {
        if (c[j] <= m) { 
            res = j; 
            break; 
        }
    }
    cout << res << endl;
    return 0;
}