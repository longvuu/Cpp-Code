/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
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
    ll n;
    ll r;
    cin >> n >> r;
    vector<ll> d(n);
    for(ll i = 0; i < n; i++) {
        cin >> d[i];
    }
    ll res = 0;
    ll j = 0;
    for(ll i = 0; i < n; i++) {
        while(j < n && d[j] - d[i] <= r) j++;
        res += n - j;
    }
    
    cout << res;
    return 0;
}