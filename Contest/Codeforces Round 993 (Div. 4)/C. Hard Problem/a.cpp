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
    
    ll t;
    cin >> t;
    while (t--) {
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll x = min(a, m);
        ll y = min(b, m);
        ll s = m - x + m - y;
        ll res = x + y + min(c, s);
        cout << res << "\n";
    }
    
    return 0;
}