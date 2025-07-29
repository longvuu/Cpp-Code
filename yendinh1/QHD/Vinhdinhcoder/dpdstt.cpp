/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpdstt"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll gcd(ll A, ll B)
{
    if (B == 0)
        return A;
    else
        return gcd(B, A % B);
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1), dp(n+1, 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll res = dp[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]&&gcd(a[j],a[i])==1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
