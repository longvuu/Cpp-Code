/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "quasong"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll MOD = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(k);
    for(int i=0;i<k;i++){
        cin >> a[i].fi >> a[i].se;
    }
    vector<ll> dp(n+1,0);
    vector<ll> s(n+1,0);
    dp[1] = 1;
    s[1] = 1;
    for(int i=2;i<=n;i++){
        s[i] = s[i-1];
        for(int j=0;j<k;j++){
            ll l = a[j].fi;
            ll r = a[j].se;
            ll l1 = max(1LL, i-r);
            ll r1 = max(0LL, i-l);
            if(r1 >= l1){
                ll sum = s[r1] - (l1 > 1 ? s[l1-1] : 0);
                dp[i] = (dp[i] + sum + MOD) % MOD;
            }
        }
        s[i] = (s[i] + dp[i]) % MOD;
    }
    
    cout << dp[n];
    return 0;
}