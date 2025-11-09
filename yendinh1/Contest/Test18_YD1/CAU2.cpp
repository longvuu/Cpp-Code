/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define taskname "CAU2"
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
    int n;
    cin >> n;
    ll k = 0;
    ll t = 0;
    for(int i = 0; i < n; i++) {
        ll h; cin >> h;
        k += h;
        t += h * h;
    }
    ll res = (k * k - t) / 2;
    cout << res;
    
    return 0;
}