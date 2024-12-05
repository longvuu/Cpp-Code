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
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>a(n+1,vector<ll>(m+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    ll dem=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i][j]%3==0){
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}