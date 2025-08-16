/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "dpknsca"
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
        ll m,n,s=0;
        cin >> n;
        vector<ll> a(n+1);
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
            s+=a[i];
        }
        vector<ll> dp(s+1,0);
        dp[0] = 1;
        for(ll i = 1; i <= n; i++) {
            for(ll j = s; j >= a[i]; j--) {
                if(dp[j-a[i]] == 1) {
                    dp[j] = 1;
                }
            }
        }
        bool check = true;
        for(ll i = 0; i <= s; i++) {
            if(dp[i] == 1) {
                if(!check) {
                    cout << ' ';
                }
                cout << i;
                check = false;
            }
        }
        cout << '\n';
    }
    return 0;
}