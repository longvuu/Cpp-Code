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
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a / gcd(a,b)) * b;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a,b;
    cin >> a >> b;
    cout << lcm(a,b);
    return 0;
}