/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU2"
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    multiset<ll> s;
    for (ll i = 0; i < n; i++) 
    {
        multiset<ll>::iterator it = s.upper_bound(a[i]);
        if (it != s.end()) s.erase(it);
        s.insert(a[i]);
    }
    cout << s.size();
    return 0;
}