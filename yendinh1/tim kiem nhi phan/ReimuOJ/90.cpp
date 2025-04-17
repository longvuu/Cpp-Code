/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/90
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(vector<ll> a, ll n, ll k, double mid) {
    vector<double> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i] - mid;
    vector<double> s(n + 1, 0);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i - 1];
    double t = 0;
    for (int i = k; i <= n; i++) {
        t = min(t, s[i - k]);
        if (s[i] - t >= 0) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    double l = -1e9, r = 1e9, res = 0;
    for (int j = 0; j < 100; j++) {
        double mid = (l + r) / 2;
        if (check(a, n, k, mid)) {
            res = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << res << '\n';
    return 0;
}