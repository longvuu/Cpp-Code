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

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,x;
    ll res=0;
    cin >> n;
    for(ll i =0;i<n;i++){
        cin >> x;
        if(x==1){
            res++;
        }else{
            res--;
        }
    }
    cout << abs(res);
    return 0;
}