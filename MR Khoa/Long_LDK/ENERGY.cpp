/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "ENERGY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    int dem = 0;
    while (n > 0) {
        if (n & 1) dem++; 
        n >>= 1; 
    }
    cout << dem << endl;
    return 0;
}