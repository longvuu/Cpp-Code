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
ll get(ll i) {
    ll t = (i - 1) / 6;
    ll j = (i - 1) % 6;
    if (j < 3) {
        return 6 * t + j + 1;
    } else {
        return 6 * t + 9 - j;
    }
}

ll sum(ll n) {
    if (n == 0) return 0;
    ll t = n / 6;
    ll k = n % 6;
    ll res = 0;
    res += t * 21 + 36 * t * (t - 1) / 2;
    for (ll i = 1; i <= k; i++) {
        res += get(t * 6 + i);
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
    ll l,r,res=0;
    cin >> l >> r;
    res = sum(r) - sum(l - 1);
    cout << res;

    
    return 0;
}