/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "dslop"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

void chuanhoa(string &s) {
    stringstream ss(s);
    string x, res;
    while (ss >> x) {
        if (!res.empty()) res += " ";
        res += x;
    }
    s = res;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        chuanhoa(s);
        a.pb(s);
    }

    for (const auto &n : a) {
        cout << n << endl;
    }
    
    return 0;
}