/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool ta(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    string s;
    cin >> s;
    ll n = s.length();
    ll d1 = 0, d2 = 0;
    for(int i = 0; i < n; i++) {
        if(ta(s[i])) {
            d1++;
        } else {
            d2++;
        }
    }
    ll result = d1 * d2;
    cout << result;
    return 0;
}
