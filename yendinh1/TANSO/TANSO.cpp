/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TANSO"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int res=0;
    string st;
    getline(cin, st);
    map<char, int> mp;
    for(int i=0;i<st.size();i++) {
        if(st[i] >= 'a' && st[i] <= 'z') {
            st[i] = st[i] - 32;
        }
    }
    for(int i=0;i<st.size();i++) {
        if(st[i] >= 'A' && st[i] <= 'Z') {
            mp[st[i]]++;
            res=max(res, mp[st[i]]);
        }
    }
    for(char i='A';i<='Z';i++) {
        if(mp[i] == res) {
            cout << i;
            break;
        }
    }
    return 0;
}