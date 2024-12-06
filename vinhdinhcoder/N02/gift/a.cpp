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
    unsigned ll n,x,y,u,v,t;
    cin>>n;
    while(n--)
    {
        cin>>x>>y>>u>>v>>t;
        if(u>v) u=min(u,v+t);
        else v=min(v,u+t);
        cout<<x*u+y*v<<endl;
    }
    
    return 0;
}