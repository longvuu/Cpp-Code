/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ctc96"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a,b,c,d;
    cin>>a >> b >> c >> d;
    cout << gcd(a,gcd(b,gcd(c,d)));
    return 0;
}