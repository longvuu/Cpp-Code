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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll res=0;
    ll i=0;
    for(ll &x : a){
        i++;    
        cin >> x;
        if(x==k){
            res=i;
            break;
        }
    }
    if(res!=0){
        cout << "CO K O VI TRI " << res;
    }else{
        cout << "KHONG CO K";
    }
    
    return 0;
}