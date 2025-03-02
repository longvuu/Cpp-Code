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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a;
    a.pb(1);
    ll l = 0, r = 0;
    while(a.size()<n){
        ll s1=2*a[l]+1;
        ll s2=3*a[r]+1;
        ll res=min(s1, s2);
        if (res==s1) l++;
        if (res==s2) r++;
        if (a.back()!=res){
            a.pb(res);
        }
    }
    cout << a[n-1] << endl;
    return 0;
}
