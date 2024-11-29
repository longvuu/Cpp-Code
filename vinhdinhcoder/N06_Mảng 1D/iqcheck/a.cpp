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
    ll dem =0;
    for(ll &x : a){
        cin >> x;
        if(x%2==0) dem++;
    }
    if(n-dem==1){
        for(ll x : a){
            if(x%2==1){
                cout << x;
                return 0;
            }
        }
    }
    else{
        for(ll x : a){
            if(x%2==0){
                cout << x;
                return 0;
            }
        }
    }
    
    return 0;
}