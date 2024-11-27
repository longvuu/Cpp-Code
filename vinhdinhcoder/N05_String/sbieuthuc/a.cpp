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
    string s;
    cin >> s;
    ll res = 0;
    ll n = s.size();
    ll x = 0;
    ll y = 1;
    
    for(ll i = 0; i < n; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + (s[i] - '0');
        } else {
            res += y * x;
            x = 0;
            if(s[i] == '+') y = 1;
            else y = -1;
        }
    }
    res += y * x;  
    
    cout << res << endl;
    return 0;
}