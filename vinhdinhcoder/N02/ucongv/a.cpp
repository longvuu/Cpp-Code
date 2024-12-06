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

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a;
    cin >> a;
    bool kt=true;
    for (ll u=1; u<=a; u++) {
        for (ll v=u; v<=a; v++) if (a==u+v) {
            cout << u << " " << v;
            kt=false;
            break;
        }
        if (kt==false) break;
    }
    if (kt) cout << "0 0";
    
    return 0;
}