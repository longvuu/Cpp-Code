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

string sum(string n, string m) {
    if (n.length() < m.length())
        swap(n, m);
    
    ll x = n.length();
    ll y = m.length();
    ll t = 0;
    string res;
    
    for (ll i = 0; i < y; i++) {
        ll s = (n[x-1-i] - '0') + (m[y-1-i] - '0') + t;
        res.push_back(s % 10 + '0');
        t = s / 10;
    }
    
    for (int i = y; i < x; i++) {
        ll s = (n[x-1-i] - '0') + t;
        res.push_back(s % 10 + '0');
        t = s / 10;
    }
    
    if (t)
        res.push_back(t + '0');
    
    reverse(res.begin(), res.end());
    return res;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st, s;
    cin >> st >> s;
    cout << sum(st, s) << endl;
    return 0;
}