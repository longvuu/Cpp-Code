/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a, b;
    for (ll i = 1; i <= n; i++) {
        if (i % 2 == 0) a.pb(i);
        else b.pb(i);
    }
    vector<ll> combined;
    ll i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i < a.size()) combined.pb(a[i++]);
        if (j < b.size()) combined.pb(b[j++]);
    }
    if (l < 1) l = 1;
    if (r > combined.size()) r = combined.size();

    ll res = 0;
    for (ll k = l - 1; k < r; k++) {
        res += combined[k];
    }
    
    cout << res; 
    return 0;
}