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
    ll s1=0,s2=0;
    pair<ll, ll> a[n];
    vector<ll> b,c;
    for(ll i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        s2=max(s2,abs(a[i].fi-a[i].se));
        s1=max(s1,abs(a[i].fi=(a[i].fi-a[i].se)));
    }
    cout << s1+s2;
    return 0;
}