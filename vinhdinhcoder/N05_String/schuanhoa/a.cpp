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
    getline(cin, st);
    ll n = st.length();
    
    while (st[0] == ' ') {
        st.erase(0, 1);
    }
    
    while (st[st.length()-1] == ' ') {
        st.pop_back();
    }
    
    string res = "";
    bool kt = false;
    for (char c : st) {
        if (c == ' ') {
            if (!kt) {
                res += c;
                kt = true;
            }
        } else {
            res += c;
            kt = false;
        }
    }
    
    cout << res;
    return 0;
}