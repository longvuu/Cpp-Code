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
    for(ll i=1;i<=n;i++){
        sort(a[i].begin() + 1, a[i].end());
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}