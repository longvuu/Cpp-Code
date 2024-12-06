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
    
    double a, b, R;
    cin >> a >> b >> R;
    
    double s1 = a * b;
    double s2 = M_PI * R * R;
    double res = s1 - s2;
    
    cout << fixed << setprecision(2) << res << endl;
    
    return 0;
}