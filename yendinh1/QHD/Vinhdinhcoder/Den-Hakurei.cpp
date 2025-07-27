/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MOD = 1e9+7;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> c;
    c[1]=1;
    c[2]=2;
    c[3]=4;
    // c[i]=c[i-1]+c[i-2]+c[i-3]
    for(ll i =4;i<=n;i++){
        c[i]=(c[i]+c[i-2]+c[i-3])%MOD;
    }
    cout << c[n];
    return 0;
}
