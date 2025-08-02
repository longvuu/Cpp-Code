/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpcoutliq"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MOD = 1000000007;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1), dp(n+1, 1), s(n+1, 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];

    ll k = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]) {
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    s[i] = s[j];
                } else if(dp[j] + 1 == dp[i]) {
                    s[i] = (s[i] + s[j]) % MOD;
                }
            }
        }
        k = max(k, dp[i]);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] == k) {
            res = (res + s[i]) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}
