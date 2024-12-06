/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ctc97"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

string NORM(string s) {
    ll i = 0;
    while (i < s.length() - 1 && s[i] == '0') i++;
    return s.substr(i);
}

bool COMP(string u, string v) {
    u = NORM(u);
    v = NORM(v);
    if (u.length() != v.length())
        return u.length() > v.length();
    return u > v;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string u, v;
    cin >> u >> v;
    if (COMP(u, v)) {
        cout << u;
    } else {
        cout << v;
    }
    
    return 0;
}