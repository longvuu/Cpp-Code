/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/440
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(vector<ll> w,vector<ll> v, int k, double x) {
    int n = w.size();
    vector<pair<double, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {v[i] - x * w[i], i};
    }
    sort(a.begin(), a.end(), greater<pair<double, int>>());
    double t = 0;
    for (int i = 0; i < k; i++) {
        t += a[i].fi;
    }
    return t >= 0;
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
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    double l = 0, r = 1e9, res = 0;
    for (int j = 0; j < 100; j++) {
        double mid = (l + r) / 2;
        if (check(w, v, k, mid)) {
            res = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}