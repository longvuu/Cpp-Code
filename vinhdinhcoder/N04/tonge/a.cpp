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
    double n;
    cin >> n;
    double res = 0; 
    ll i = 1;
    while(res < n) {
        res += 1.0 / (i * i);
        i++;
    } 
    cout << fixed << setprecision(9) << res;
    return 0;
}