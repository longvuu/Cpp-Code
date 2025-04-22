/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll  n, k;
vector<pair<ll , ll >> a; 
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    a.resize(n);
    for (ll  i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    double l = 0, r = 1e9;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(8) << l << endl;
    return 0;
}