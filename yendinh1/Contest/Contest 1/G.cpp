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
    
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto check = [&](double x) {
        vector<double> b(n);
        for(int i = 0; i < n; i++) b[i] = a[i] - x;
        vector<double> s(n + 1, 0);
        for(int i = 0; i < n; i++) 
            s[i + 1] = s[i] + b[i];
        double minPref = 0;
        for(int r = 0; r < n; r++) {
            ll sum = 0;
            for(int l = r; l >= 0; l--) {
                sum += a[l];
                if(sum >= k && s[r + 1] - s[l] >= 0) 
                    return true;
            }
        }
        return false;
    };
    double l = 0, r = 1e9;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    
    cout << fixed << setprecision(4) << l;
    return 0;
}