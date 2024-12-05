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
    cin >> n;
    ll s=0;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(ll i=0;i<n;i++){
        ll s=0;
        for(ll j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]%2==0){
                s+=a[i][j];
            }
        }
        cout << s << endl;
    }
    return 0;
}