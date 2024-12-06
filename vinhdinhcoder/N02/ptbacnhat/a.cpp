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
    
    int a, b;
    cin >> a >> b;
    
    if (a == 0) {
        if (b == 0) {
            cout << "VO SO NGHIEM";
        } else {
            cout << "VO NGHIEM";
        }
    } else {
        cout << "PT CO NGHIEM" << endl << "X = ";
        cout << fixed << setprecision(2) << (-1.0 * b / a);
    }
    
    return 0;
}