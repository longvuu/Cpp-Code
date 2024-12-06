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
    ll a,b,c;
    cin >> a >> b >> c;
    if(a < 0) cout << a*a << endl;
    else if(a > 0) cout << a*a*a << endl;
    
    if(b < 0) cout << b*b << endl;
    else if(b > 0) cout << b*b*b << endl;
    
    if(c < 0) cout << c*c << endl;
    else if(c > 0) cout << c*c*c << endl;
    
    return 0;
}