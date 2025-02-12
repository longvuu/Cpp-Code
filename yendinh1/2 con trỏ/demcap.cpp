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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    map<ll, ll> b;
    ll dem = 1;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(ll i = 0; i < n; i++) {
        if (i < n - 1 && a[i] == a[i + 1]) {
            dem++;
        } else {
            b[a[i]] = dem;
            dem = 1;
        }
    }
    ll l = 0, r = n - 1, res = 0;
    while (l < r) {
        if (a[l] + a[r] == x) {
            if(a[l]!=a[r]){
                res += b[a[l]] * b[a[r]];
            }else{
                res+=(r-l+1)-(r-l)/2;
            }
            l += b[a[l]];
            r -= b[a[r]];
        } else if (a[l] + a[r] > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << res;
    return 0;
}
