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
    ll W, L, X;
    cin >> W >> L >> X;
    ll left = 0, right = 1e18;
    ll res = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        long double k = (long double)(W + mid) / (W + L + mid) * 100;
        
        if (k >= X) {
            res = min(res, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << res;
    return 0;
}