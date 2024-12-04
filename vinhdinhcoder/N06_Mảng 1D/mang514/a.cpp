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
    ll s1=0,s2=LLONG_MAX;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        s1=max(s1,a[i]);
        s2=min(s2,a[i]);
    }
    ll x,y; 
    for(ll i =0;i<n;i++){
        if(a[i]==s1) x=i;
        if(a[i]==s2) y=i;
    }
    swap(a[x],a[y]);
    for(ll i =0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}