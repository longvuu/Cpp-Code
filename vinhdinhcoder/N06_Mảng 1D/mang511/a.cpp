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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll dem=0;
    if(a[0]<a[1]){
        dem++;
    }
    if(a[n-1]<a[n-2]){
        dem++;
    }
    for(ll i = 1; i < n-1; i++) {
        if(a[i]<a[i-1] && a[i]<a[i+1]){
            dem++;
        }
    }
    cout << dem;
    return 0;
}