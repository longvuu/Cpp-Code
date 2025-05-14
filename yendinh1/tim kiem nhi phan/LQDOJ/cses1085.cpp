/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/cses1085
*/
#include <bits/stdc++.h>
#define taskname ""
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
    // CSES - Array Division | Chia mảng
    ll n,k;
    cin >> n >> k;
    ll l = 0, r = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l= max(l, a[i]);
        r += a[i];
    }
    while (l < r) {
        ll m = (l + r) / 2;
        ll sum = 0, t = 1;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > m) {
                t++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }
        if (t > k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l;
    return 0;
}