/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU5"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll k;
    cin >> k;
    ll res = LLONG_MAX;
    for(ll i = 1, p=1; i<=9; i++, p=p*10+1) {
        for(ll j = 9, c; j>0; j--) {
            c=p*j; 
            if(c%k == 0) res = min(res, c/k);
        }
    }
    cout << (res % MOD) << endl;
    return 0;
}