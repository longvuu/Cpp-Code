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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(m+1, 0));
    vector<vector<ll>> d(n+1, vector<ll>(m+1, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            d[i][j] = a[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
        }
    }
    ll q;
    cin >> q;
    while(q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;  
        cout << d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1] << '\n';
    }

    return 0;
}