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
    
    ll x, y;
    for(ll i = 0; i <= 36; i++) {
        x = i;
        y = 36 - i;   
        if(2*x + 4*y == 100) {
            cout << x << " " << y;
            break;
        }
    }
    
    return 0;
}