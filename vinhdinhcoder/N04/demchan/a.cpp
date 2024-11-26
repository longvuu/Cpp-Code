/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#include <iostream>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;
bool check(ll n){
    ll res=0;
    while(n!=0){
        res+=n%10;
        n/=10;
    }
    return res%3==0;
}
ll subtask1(ll a, ll b) {
    ll dem=0;
    for(ll i=a;i<=b;i++){
        if(check(i)&&i%2==0) dem++;
    }
    return dem;
}
ll subtask2(ll a, ll b) {
    ll n=0;
    if (a % 6 != 0) {
        a += 6 - (a % 6);
    }
    n = (b - a) / 6;
    return n+1;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a, b, n;
    cin >> a >> b;
    if(b<=1e5) cout<<subtask1(a,b);
    else cout<<subtask2(a,b);
    return 0;
}