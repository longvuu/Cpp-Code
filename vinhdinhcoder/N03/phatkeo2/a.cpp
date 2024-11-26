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
    ll res=1;
    ll s=1;
    ll dem =0;
    for(ll i =1;i<=n;i++){
        if(i!=1){
            s+=3;
            res+=s;
        }
        if(k-res>=0){
            dem++;
        }
    }
    cout << dem;
    return 0;
}