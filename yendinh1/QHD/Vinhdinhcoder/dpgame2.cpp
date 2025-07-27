/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpgame2"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll a[100006],c[100006];
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k,res=0;
    cin >> n >> k;
    for(ll i =1;i<=n;i++) cin >> a[i];
    c[0]=0;
    for(ll i =1;i<=n;i++){
        c[i]=c[i-1]+a[i];
        for(ll j=2;j<=i&&j<=k;j++){
            c[i]=max(c[i],c[i-j]+a[i]);
        }
        res=max(res,c[i]);
    }
    cout << res;
    return 0;
}
