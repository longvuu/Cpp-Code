/*
    @author longvuuuu
<<<<<<< HEAD
    @problem https://marisaoj.com/problem/440
=======
>>>>>>> fad832f90b4d45cd6e957ec218786d3bddf0a454
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
<<<<<<< HEAD
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
=======
ll  n, k;
vector<pair<ll , ll >> a; // (value, weight)
bool check(double x) {
    vector<double> s(n);
    for (ll  i = 0; i < n; i++) {
        s[i] = a[i].fi - x * a[i].se;
    }
    
    sort(s.begin(), s.end(), greater<double>());
    
    double t = 0;
    for (ll  i = 0; i < k; i++) {
        t += s[i];
    }
    
    return t >= 0;
}
int  main() {
>>>>>>> fad832f90b4d45cd6e957ec218786d3bddf0a454
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
<<<<<<< HEAD
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
=======
    cin >> n >> k;
    a.resize(n);
    for (ll  i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    double l = 0, r = 1e9;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        if (check(mid)) {
>>>>>>> fad832f90b4d45cd6e957ec218786d3bddf0a454
            l = mid;
        } else {
            r = mid;
        }
    }
<<<<<<< HEAD
    cout << fixed << setprecision(9) << res << '\n';
=======
    cout << fixed << setprecision(8) << l << endl;
>>>>>>> fad832f90b4d45cd6e957ec218786d3bddf0a454
    return 0;
}