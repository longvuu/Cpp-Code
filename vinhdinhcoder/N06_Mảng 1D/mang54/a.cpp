/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
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
    ll res=0;
    for(ll &x : a){
        cin >> x;
        res=max(res,x);
    }
    ll i=0;
    for(ll x : a){
        i++;
        if(x==res){
            cout << x << " " << i;
            return 0;
        }
    }
    
    return 0;
}   