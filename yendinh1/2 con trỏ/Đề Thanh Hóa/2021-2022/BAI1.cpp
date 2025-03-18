/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,a,b;
    cin >> n >>  a >> b;
    ll s1=0,s2=0;
    if(a>b){
        s1=a-b;
    }else{
        s1=0;
    }
    if(b>n-a){
        s2=a-(b-(n-a));
    }else{
        s2=a;
    }
    cout << s1 << " " << s2;
    return 0;
}