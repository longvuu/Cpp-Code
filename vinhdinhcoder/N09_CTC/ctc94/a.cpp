/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ctc94"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll tinh(ll n){
    ll res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        cout << x << " " << tinh(x) << '\n';
    }
    return 0;
}