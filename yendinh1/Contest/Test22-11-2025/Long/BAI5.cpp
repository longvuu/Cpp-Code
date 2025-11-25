#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N =1e6;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI5.INP","r",stdin);
    freopen("BAI5.OUT","w",stdout);
    ll n;
    cin >> n;
    vector<ll> dp(n+2);
    dp[1]=1;
    dp[2]=2;
    for(ll i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    cout << dp[n];
    return 0;
}
