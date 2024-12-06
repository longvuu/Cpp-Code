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
    
    double h, R;
    cin >> h >> R;
    
    const double PI = M_PI;
    double res = (1.0/3.0) * PI * R * R * h;
    
    cout << fixed << setprecision(8) << res;
    
    return 0;
}