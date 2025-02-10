/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int minLength(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            return 1; 
        }
    }
    return n;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minLength(s) << endl;
    }
    return 0;
}