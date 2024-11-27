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
    string st;
    string s;
    ll dem=0;
    getline(cin,st);
    ll n = st.length();
    for(ll i = n - 1; i >= 0; i--) {
        if(st[i]==' '){
            dem++;
        }
    }
    if(dem==0) {
        cout << st;
        return 0;
    }
    for(ll i =n - 1; i >= 0; i--) {
        if(st[i] != ' ') {
            s = st[i] + s;
        } else {
            cout << s << " ";
            break;
        }
    }
    return 0;
}