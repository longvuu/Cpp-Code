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
int n, m, q;
vector<vector<ll>> A, s;
void tinhtong() {
    s.assign(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = A[i-1][j-1] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
}
ll solve(ll a, ll b, ll c, ll d) {
    return s[c+1][d+1] - s[a][d+1] - s[c+1][b] + s[a][b];
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> n >> m >> q;
    A.assign(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    tinhtong();
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a-1, b-1, c-1, d-1) << '\n';
    }
    
    return 0;
}