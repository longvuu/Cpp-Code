/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpsmax"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    ll res=0,t=0;
    vector<ll> a(n+1),dp(n+1,1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (ll j = 1; j < i; j++) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
