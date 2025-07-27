/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpfibo1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MOD = 1e9+7;
ll f[10000000];

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    f[1]=1;
    f[2]=1;
    for(ll i =3;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
    cout << f[n];
    return 0;
}
