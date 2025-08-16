/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "dpknsco"
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
    ll t;
    cin >> t;
    while(t--){
        ll m,n;
        cin >> m >> n;
        vector<ll> a(n+1);
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<ll> dp(m+1,1E9);
        dp[0] = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = a[i]; j <= m; j++) {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
        if(dp[m] == 1E9) {
            cout << -1 << endl;
        } else {
            cout << dp[m] << endl;
        }
    }
    return 0;
}