/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpgame"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MOD =25071987;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> f(n+1),s(n+1,1);
    f[0]=0;
    f[1]=1;
    while(k--){
        ll t;
        cin >> t;
        s[t]=0;
    }
    for(ll i=2;i<=n;i++){
        f[i]=(s[i]*(f[i-1]+f[i-2]))%MOD;
    }
    cout << f[n];
    return 0;
}
