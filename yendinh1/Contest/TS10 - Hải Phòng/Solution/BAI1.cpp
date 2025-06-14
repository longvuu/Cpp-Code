/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI1"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tinh(ll r) {
    if (r < 0) return 0;
    ll r2 = r * r;
    ll res = 0;
    for (ll x = 0; x <= r; x++) {
        ll x2 = x * x;
        if (x2 > r2) continue;
        ll yMax = (ll)floorl(sqrtl((long double)(r2 - x2)));
        if (x == 0)
            res += 2 * yMax + 1;
        else
            res += 2 * (2 * yMax + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll r1, r2;
    cin >> r1 >> r2; 
    ll ans = tinh(r2) - tinh(r1);
    cout << ans << "\n";
    return 0;
}