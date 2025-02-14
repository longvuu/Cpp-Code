/*
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
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    
    sort(a.begin(), a.end());
    
    for (ll i = 0; i < n - 3; i++) {
        for (ll j = i + 1; j < n - 2; j++) {
            ll l = j + 1, r = n - 1;
            while (l < r) {
                ll sum = a[i].fi + a[j].fi + a[l].fi + a[r].fi;
                if (sum == x) {
                    cout << "YES";
                    return 0;
                } else if (sum < x) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    
    cout << "NO";
    return 0;
}
