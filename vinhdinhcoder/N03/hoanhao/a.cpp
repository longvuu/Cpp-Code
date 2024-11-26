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
bool check(ll n){
    ll res=0;
    for(ll i=1;i<=n/2;i++){
        if(n%i==0) res+=i;
    }
    return res==n;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    if(check(n)) cout << "YES";
    else cout << "NO";
    return 0;
}