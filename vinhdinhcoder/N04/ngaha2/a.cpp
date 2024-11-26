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

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m;
    cin >> n >> m;
    ll res = n;
    ll dem = 0;
    while (res < m) {
        double s = res * 0.1;
        ll k = (ll)(s + 0.5); 
        res += k;
        dem++;
    }
    cout << dem;
    return 0;
}