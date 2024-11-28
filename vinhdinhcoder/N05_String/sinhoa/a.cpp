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
char chuhoa(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    getline(cin, st);
    ll n = st.length();
    for(int i = 0; i < n; i++) {
        if(st[i]>='a' && st[i]<='z'){ 
            cout << chuhoa(st[i]);
        }else{
            cout << st[i];
        }
    }
    return 0;
}