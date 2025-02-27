/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
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
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> s;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0, res = 0; 
    ll x = 0; 
    for(ll r = 0; r < n; r++) {
        s[a[r]]++;
        x = max(x, s[a[r]]);
        while(l <= r && x >= k) {
            res += n - r;
            s[a[l]]--;
            if(s[a[l]] == x - 1) {
                x--;
            }
            l++;
        }
    }
    cout << res;
    return 0;
}
