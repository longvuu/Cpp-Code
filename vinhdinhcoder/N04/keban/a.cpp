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
    ll a,b;
    cin >> a >> b;
    ll dem=0;
    ll res =a;
    ll k=0;
    while(res<b){
        dem++;
        res*=2;
        if(res<=b){
            k=max(k,dem);
            
        }
    }
    cout << k;
    return 0;
}