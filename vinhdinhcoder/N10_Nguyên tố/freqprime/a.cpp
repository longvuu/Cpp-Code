/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "freqprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool snt(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    getline(cin,st);
    map<char, ll> a;
    for(char c : st) {
        a[c]++;
    }
    ll res = 0;
    for(auto p : a) {
        if(snt(p.second)) {
            res += p.second;
        }
    }
    cout << res;
    return 0;
}