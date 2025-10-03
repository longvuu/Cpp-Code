/* 
    @author longvuuuu 
*/
#include <bits/stdc++.h>
#define taskname "BOBA"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll C2(ll x) { 
    if (x >= 2) return x * (x - 1) / 2; 
    else return 0; 
}
ll C3(ll x) { 
    if (x >= 3) return x * (x - 1) * (x - 2) / 6; 
    else return 0; 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, q; 
    cin >> n >> q;
    vector<ll> a(n+1);
    for(ll i=1; i<=n; i++) cin >> a[i];
    vector<ll> s(n+1, 0);
    for(ll i=1; i<=n; i++) s[i] = s[i-1] + ((a[i] & 1) == 0);
    while(q--) {
        ll l, r; cin >> l >> r;
        ll len = r - l + 1;
        if(len < 3) {
            cout << 0 << '\n'; 
            continue; 
        }
        ll e = s[r] - s[l-1];
        ll o = (ll)len - e;
        ll ans = C3(e) + e * C2(o);
        cout << ans << '\n';
    }
    return 0;
}