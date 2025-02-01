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
    
    ll n;
    cin >> n;
    
    if (n <= 1) {
        cout << -1 << endl;
        return 0;
    }
    
    ll res = -1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = i;
            break;
        }
    }
    
    if (res == -1 && n > 1) {
        res = n;
    }
    
    cout << res << endl;
    
    return 0;
}