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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n - 1, dem = 0;
    while (l < r) {
        if (a[l] + a[r] == x) {
            ll d1 = 1, d2 = 1;
            if(a[l] != a[r]){
                while (l + d1 < r && a[l] == a[l + d1]) {
                    d1++;
                }
                while (r - d2 > l && a[r] == a[r - d2]) {
                    d2++;
                }
            } else {
                dem += (r - l + 1) * (r - l) / 2;
                break;
            }
            dem += d1 * d2;
            l += d1;
            r -= d2;
        } else if (a[l] + a[r] > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << dem;
    return 0;
}
