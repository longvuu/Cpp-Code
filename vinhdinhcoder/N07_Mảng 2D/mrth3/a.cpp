/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
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
    ll m,n;
    cin >> m >> n;
    ll s=0;
    ll res=0;
    vector<vector<ll>>a(m+1,vector<ll>(n+1,0));
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(ll i=1;i<=m;i++){
        ll s=0;
        for(ll j=1;j<=n;j++){
            s+= a[i][j];
        }
        res = max(res,s);
    }
    cout << res;
    return 0;
}