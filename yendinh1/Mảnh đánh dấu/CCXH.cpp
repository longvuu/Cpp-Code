/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CCXH"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll res=0,k=1e5;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm (ll a, ll b) {
    return a/gcd(a,b)*b;
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    getline(cin,st);
    map<char, ll> mp;
    for(ll i=0;i<st.size();i++) {
        if(st[i] >= 'a' && st[i] <= 'z') {
            st[i] = st[i] - 32;
        }
    }
    for(ll i=0;i<st.size();i++) {
        if(st[i] >= 'A' && st[i] <= 'Z') {
            mp[st[i]]++;
            res=max(res, mp[st[i]]);
        }
    }
    cout << lcm(res,k);
    return 0;
}