/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tinh(ll R) {
    if (R < 0) return 0;
    ll R2 = R * R;
    ll res = 0;
    for (ll x = 0; x <= R; x++) {
        ll x2 = x * x;
        if (x2 > R2) continue;
        ll yMax = (ll)floorl(sqrtl((long double)(R2 - x2)));
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
    ll R1, R2;
    cin >> R1 >> R2; 
    ll ans = tinh(R2) - tinh(R1);
    cout << ans << "\n";
    return 0;
}