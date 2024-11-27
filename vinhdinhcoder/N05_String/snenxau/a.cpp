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

string nen(string st) {
    if (st.empty()) return "";
    string s;
    int dem = 1;
    
    for(int i = 0; i < st.length() - 1; i++) {
        if(st[i] == st[i + 1]) {
            dem++;
        } else {
            s += to_string(dem);
            s += st[i];
            dem = 1;
        }
    }
    s += to_string(dem);
    s += st.back();
    return s;
}

string giainen(string st) {
    string s;
    ll n = 0;
    
    for(ll i = 0; i < st.length(); i++) {
        if(isdigit(st[i])) {
            n = n * 10 + (st[i] - '0');
        } else {
            if(i > 0 && isdigit(st[i-1])) {
                for(ll j = 0; j < n; j++) {
                    s += st[i];
                }
                n = 0;
            }
        }
    }
    return s;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string s1,s2;
    cin >> s1 >> s2;
    cout << nen(s1) << '\n';
    cout << giainen(s2);
    
    return 0;
}