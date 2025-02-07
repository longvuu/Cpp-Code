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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i =0;i<=n;i++) cin >> a[i];
    ll l=0, r=0, sum=0, dem=0;
    while (r < n) {
        sum += a[r];
        while (sum > x && l <= r) {
            sum -= a[l];
            l++;
        }
        dem += (r - l + 1);
        r++;
    }
    cout << dem << endl;
    return 0;
}

