/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ctc93"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll int a[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 
    479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 
    355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

int simp() {
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }
    
    return 0;
}