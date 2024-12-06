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
    
    double a, b, c;
    cin >> a >> b >> c;
    
    double d = b*b - 4*a*c;
    cout << fixed << setprecision(2);
    
    if (d < 0) {
        cout << "VO NGHIEM"; 
    } else if (d == 0) {
        double x = -b / (2.0 * a);
        cout << "PT CO NGHIEM KEP" << endl;
        cout << "X = " << x;
    } else {
        double x1 = (-b - sqrt(d)) / (2.0 * a);
        double x2 = (-b + sqrt(d)) / (2.0 * a);
        cout << "PT CO HAI NGHIEM" << endl;
        cout << "X1 = " << x2 << '\n' << "X2 = " << x1;
    }
    
    return 0;
}