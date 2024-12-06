/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "matran"
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
    vector<vector<double>> a(n, vector<double>(m));
    for(ll i = 0; i < n; i++) {
        double res=0;
        for(ll j = 0; j < m; j++) {
            cin >> a[i][j];
            res=max(res,a[i][j]);
        }
        cout << fixed << setprecision(2)<< res << endl;
    }
    return 0;
}