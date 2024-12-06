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
    ll a[3];
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4);
    if(a[1]==a[2]||a[2]==a[3]) cout << "LA TAM GIAC CAN";
    else cout << "KHONG PHAI TAM GIAC CAN";
    
    return 0;
}