/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a,b;
    cin >> a >> b;
    a= ' ' + a;
    b= ' ' + b;
    vector<ll> x(a.size()), y(b.size());
    for(ll i = 1; i < a.size(); i++) {
        x[i] = (a[i] - '0');
    }
    for(ll i = 1; i < b.size(); i++) {
        y[i] = (b[i] - '0');
    }
    ll n = a.size() - 1, m = b.size() - 1;
    vector<vector<ll>> c(n + 1, vector<ll>(m + 1, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(x[i] == y[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }
    string z = "";
    ll i = n, j = m;
    while(i > 0 && j > 0) {
        if(x[i] == y[j]) {
            z = char(x[i] + '0') + z;
            i--; j--;
        } else if(c[i-1][j] > c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << z;
    return 0;
}