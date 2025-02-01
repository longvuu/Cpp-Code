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

long double a, b, c, x;

long double F(long double x) {
    if (fabsl(x) > 1e18) return LDBL_MAX;
    long double ax = a * x;
    long double ax2 = ax * x;
    long double bx = b * x;
    return ax2 + bx + c;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> c >> b >> a; 
    cin >> x;
    
    x = roundl(x * 100) / 100.0L;
    
    long double fx = F(x);
    if (fabsl(fx) > 1e18) {
        cout << fixed << setprecision(3) << LDBL_MAX;
        return 0;
    }
    
    long double fx_squared = fx * fx;
    if (fabsl(fx_squared) > 1e18) {
        cout << fixed << setprecision(3) << LDBL_MAX;
        return 0;
    }
    
    long double sum = fx + fx_squared;
    if (fabsl(sum) > 1e18) {
        cout << fixed << setprecision(3) << LDBL_MAX;
        return 0;
    }
    
    long double result = F(sum);
    result = roundl(result * 1000) / 1000.0L;
    cout << fixed << setprecision(3) << result;
    
    return 0;
}