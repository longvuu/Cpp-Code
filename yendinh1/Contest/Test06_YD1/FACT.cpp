#include <bits/stdc++.h>
#define taskname "FACT"
#define ll long long
using namespace std;
const int MOD = 20241101;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll n;
    cin >> n;
    ll t = 1;
    ll res = 0;
    ll limit = min(n, 41057LL);
    for(ll i = 1; i <= limit;i++) {
        t = (t * i) % MOD;
        res = (res + t) % MOD;
    }
    cout << res << endl;
    return 0;
}