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
    
    ll a, b, c;
    cin >> a >> b >> c;

    ll s1 = abs(a - c);
    ll s2 = abs(b - c);

    if (s1 < s2) {
        cout << "Cat_A" << endl;
    } else if (s2 < s1) {
        cout << "Cat_B" << endl;
    } else {
        cout << "Mouse_C" << endl;
    }
    
    return 0;
}