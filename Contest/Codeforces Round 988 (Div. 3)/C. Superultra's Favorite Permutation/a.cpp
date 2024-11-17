/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    ll n;
    cin >> n;
    if (n == 2) {
        cout << "1 2\n";
        return;
    }
    if (n == 3) {
        cout << "-1\n";
        return;
    }
    vector<ll> p(n);
    for (ll i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    if (n % 2 == 0) {
        for (ll i = 0; i < n; i += 2) {
            swap(p[i], p[i+1]);
        }
    } else {
        for (ll i = 0; i < n-3; i += 2) {
            swap(p[i], p[i+1]);
        }
        swap(p[n-3], p[n-2]);
        swap(p[n-2], p[n-1]);
    }
    for (ll x : p) cout << x << ' ';
    cout << '\n';
}

int main() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}