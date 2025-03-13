/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "smama"
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
    vector<ll> a;
    a.pb(4);
    a.pb(7);
    
    for (ll i = 0; i < a.size(); i++) {
        if (a[i] == n) {
            cout << i + 1;  
            return 0;
        }
        if(a[i] > n) break;
        ll s1 = a[i] * 10 + 4;
        ll s2 = a[i] * 10 + 7;
        if (s1 <= n) a.pb(s1);
        if (s2 <= n) a.pb(s2);
    }
    cout << -1;  
    return 0;
}
