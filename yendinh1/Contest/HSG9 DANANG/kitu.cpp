/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "kitu"
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
    string s;
    cin >> s;
    bool check[26] = {false};
    for(char c : s) {
        check[c - 'A'] = true;
    }
    for(int i = 0; i < 26; i++) {
        if(!check[i]) {
            cout << (char)(i + 'A');
        }
    }
    return 0;
}