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
    
    double a, z;
    cin >> a >> z;
    ll dem = 0;
    double res = a;
    while (res < z) {
        res *= 1.011; 
        dem++;
    }
    cout << dem;
    return 0;
}