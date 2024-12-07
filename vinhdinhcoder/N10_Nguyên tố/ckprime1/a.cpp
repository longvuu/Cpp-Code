/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ckprime1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool check(ll n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i<=sqrt(n);i+=2){
        if(n%i==0) return false;
    }
    return true;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin>>n;
    if(check(n)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}