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
    ll m;
    cin >> m;
    vector<vector<ll>>a(m+1,vector<ll>(m+1,0));
    a[1][1]=2;
    for(ll i=1;i<=m;i++){
        if(i!=1){
            a[i][1]=a[i-1][1]+1;
        }
        for(ll j=1;j<=m;j++){
            if(j==1) continue;
            a[i][j]=a[i][j-1]+1;
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}