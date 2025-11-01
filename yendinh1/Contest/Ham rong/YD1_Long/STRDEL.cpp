/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "STRDEL"
#define ll long long
#define fi first
#define MOD 1000000007
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
        string s;
        cin >> s;
        ll n=s.size();
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for(int len =1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(i==j){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j]=1+dp[i+1][j];
                if (s[i] == s[j] && (len == 2 || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int k=i+1;k<=j;k++){
                    if(s[i]==s[k]){
                        ll l;
                        if(k-1 >= i+1) l = dp[i+1][k-1];
                        else l = 0;
                        ll r;
                        if(k+1 <= j) r = dp[k+1][j];
                        else r = 0;
                        dp[i][j] = min(dp[i][j], l + r);
                    }
                }
            }
        }
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}