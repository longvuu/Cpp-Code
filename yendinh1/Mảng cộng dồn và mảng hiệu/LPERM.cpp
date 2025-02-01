/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "LPERM"
#define fi first
#define se second
#define simp main
using namespace std;
#define ll long long

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end());
    
    vector<ll> s(n + 1, 0);
    ll dem = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = a[i].se + 1; j <= n; j++) {
            s[j]++;
        }
        ll j = i + 1;
        while(j < n && a[j].fi <= a[i].fi + k) {
            dem += s[a[j].se];
            j++;
        }
    }
    cout << dem;
    return 0;
}