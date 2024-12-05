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

void solve(vector<ll>& a, ll n, ll avg) {
    for (ll i = 1; i < n - 1; i++) {
        if (a[i - 1] > avg) {
            ll t = a[i - 1] - avg;
            a[i - 1] = avg;
            a[i + 1] += t;
        } else if (a[i - 1] < avg) {
            ll t = avg - a[i - 1];
            a[i - 1] = avg;
            a[i + 1] -= t;
        }
    }
    cout << (a[n - 2] == a[n - 1] ? "YES" : "NO") << endl;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll sum = 0;
        bool kt = true;
        for (ll i = 0; i < n; i++) {
            if (kt && i > 0 && a[i] != a[i - 1]) {
                kt = false;
            }
            sum += a[i];
        }
        
        if (kt) {
            cout << "YES" << endl;
            continue;
        }
        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        solve(a, n, sum / n);
    }
    return 0;
}

