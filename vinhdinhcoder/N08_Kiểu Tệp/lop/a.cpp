/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "lop"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        string res, x;
        while (iss >> x) {
            res = x;
        }
        a.pb(res);
    }
    
    for (const auto& n : a) {
        cout << n << endl;
    }
    
    return 0;
}