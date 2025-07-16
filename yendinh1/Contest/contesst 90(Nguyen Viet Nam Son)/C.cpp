/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
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
    
    ll c, d;
    cin >> c >> d;
    if (d % c != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll k = d / c;
    ll ans = LLONG_MAX;
    bool ok = false;
    
    for (ll i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            ll j = k / i;
            if (__gcd(i, j) == 1) {
                ll a = c * i;
                ll b = c * j;
                ok = true;
                ans = min(ans, a + b);
            }
        }
    }
    
    if (!ok) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}