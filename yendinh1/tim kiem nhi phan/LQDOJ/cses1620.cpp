/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/cses1620
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
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2, sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) continue;
            sum += mid / a[i];
            if (sum >= t) {
                sum = t;
                break;
            }
        }
        if (sum >= t) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
    return 0;
}