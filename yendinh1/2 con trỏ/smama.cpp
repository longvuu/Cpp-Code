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
    ll l = 0, r = 0;
    while(a.size()<n){
        ll s1=a[l]*10+4;
        ll s2=a[r]*10+7;
        a.pb(s1);
        a.pb(s2);
        l++;
        r++;
    }
    for(ll i=0;i<a.size()-1;i++){
        if(a[i]==n){
            cout << i ;
            return 0;
        }
        if(a[i]>n){
            cout << -1;
            return 0;
        }
    }
    
    return 0;
}
