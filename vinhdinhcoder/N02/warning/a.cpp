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
    double a,b,k,t,v,s,x;
    cin>>a>>b>>k>>t;
    v=t*3;
    s=v/a;
    x=s/b;
    if (x*100<=k) cout<<"YES";
    else cout<<"WARNING";
    
    return 0;
}