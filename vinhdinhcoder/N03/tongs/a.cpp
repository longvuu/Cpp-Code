/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;
ll giaithua(ll n) {
    if(n == 0) return 1;
    return n * giaithua(n - 1);
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    double res = 0;
    for(ll i = 1; i <= n; i++) {
        res += 1.0/giaithua(i);
    }
    cout << fixed << setprecision(10) << res;
    return 0;
}