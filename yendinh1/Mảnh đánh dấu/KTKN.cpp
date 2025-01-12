/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "KTKN"
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
    string st;
    getline(cin,st);
    map<char, ll> mp;
    set<char> s;
    for(ll i = 0; i < st.size(); i++) {
        mp[st[i]]++;
        s.insert(st[i]);
    }
    cout << s.size() << endl;
    for(char i = 'A'; i <= 'Z'; i++) {
        if(mp[i] == 0) continue;
        cout << i << " " << mp[i] << endl;
    }
    for(char i = 'a'; i <= 'z'; i++) {
        if(mp[i] == 0) continue;
        cout << i << " " << mp[i] << endl;
    }
    for(char i = '0'; i <= '9'; i++) {
        if(mp[i] == 0) continue;
        cout << i << " " << mp[i] << endl;
    }
    return 0;
}