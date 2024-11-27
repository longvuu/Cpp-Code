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
    cin >> st;
    sort(st.begin(), st.end());
    ll dem=1;
    for(int i=0;i<st.length();i++) {
        if(st[i]!=st[i+1]) {
            cout << st[i] << " " << dem << endl ;
            dem=1;
        } else {
            dem++;
        }
    }
    
    return 0;
}