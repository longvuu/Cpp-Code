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

bool check(int a, int b, int c) {
    int x = a * a, y = b * b, z = c * c;
    return (x + y == z) || (x + z == y) || (y + z == x);
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int a, b, c;
    cin >> a >> b >> c;
    if (check(a, b, c)) {
        cout << "Ba so da nhap la bo so Pi-ta-go" << endl;
    } else {
        cout << "Ba so da nhap khong la bo so Pi-ta-go" << endl;
    }
    
    return 0;
}