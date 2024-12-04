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

    ll res=0;
    for(ll i =1; i <= n; i++) {
        ll x;
        cin >> x;
        if(i%2!=0){
            if(x%2==0) res+=x;
        }
    }
    cout << res;
    return 0;
}