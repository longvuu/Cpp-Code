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
    
    long long a,b,c,d,s,h,t;
    cin>>a>>b>>c>>d;
    s=abs(a-c);
    h=abs(b-d);
    t=s/h;
    if (a+t*b==c+t*d) cout<<"YES";
    else cout<<"NO";
    return 0;
}