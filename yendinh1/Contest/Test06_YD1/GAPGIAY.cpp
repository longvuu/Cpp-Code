/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "GAPGIAY"
#define ll long long
using namespace std;
ll tinh(vector<vector<ll>>& s, ll r1, ll c1, ll r2, ll c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n; 
    cin >> n;
    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    for(ll i=1;i<=n;i++) 
        for(ll j=1;j<=n;j++) 
            cin >> a[i][j];
    vector<vector<ll>> s(n+1, vector<ll>(n+1,0));
    for(ll i=1;i<=n;i++){
        ll t=0;
        for(ll j=1;j<=n;j++){
            t += a[i][j];
            s[i][j] = s[i-1][j] + t;
        }
    }
    ll res = 0;
    for(ll r=1;r<=n-1;r++){
        for(ll c=1;c<=n-1;c++){
            ll x = tinh(s, 1, 1, r, c);
            ll y = tinh(s, 1, c+1, r, n);
            ll z = tinh(s, r+1, 1, n, c);
            ll k = tinh(s, r+1, c+1, n, n);
            ll u = min(min(x,y), min(z,k));
            if(u > res) res = u;
        }
    }
    cout << res << '\n';
    return 0;
}
