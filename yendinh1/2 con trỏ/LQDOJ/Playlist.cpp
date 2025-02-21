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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    unordered_map<ll, ll> s;  
    ll res = 0;
    ll l = 0;
    for(ll r = 0; r < n; r++) {
        s[a[r]]++;
        while(s[a[r]] > 1) {
            s[a[l]]--;
            if(s[a[l]] == 0) s.erase(a[l]);
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res;
    return 0;
}