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
    string n;
    cin >> n;
    ll dem = 0;
    for(ll i = 0; i < n.size(); i++) {
        char c = n[i];
        for(char d = '0'; d <= '9'; d++) {
            if(d == c) continue;
            n[i] = d;
            
            if(n[0] == '0') continue;
            
            ll res = stoll(n);
            if(res % 3 == 0) {
                dem++;
            }
        }
        n[i] = c;
    }
    
    cout << dem;
    return 0;
}
