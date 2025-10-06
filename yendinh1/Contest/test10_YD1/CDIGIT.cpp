/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CDIGIT"
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
    ll n;
    cin >> n;
    ll res = 0;
    ll base[19];
    base[0] = 1;
    for(ll i = 1; i <= 18; i++) base[i] = base[i-1]*10;
    ll m = to_string(n).size();
    for(ll k = 1; k <= m; k++) {
        ll l = base[k-1];
        ll r = min<ll>(n, base[k]-1);
        if (l > r) continue;
        res += (r-l+1) * k;
    }
    cout << res;
    return 0;
}