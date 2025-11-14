/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define taskname "CAU3"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    multiset<ll> s; 
    ll res = 0;
    for (ll x : a) {
        auto it = s.lower_bound(x + k); 
        if (it != s.end()) {
            s.erase(it);
            s.insert(x);
        } else {
            res += x;
            s.insert(x);
        }
    }

    cout << res << '\n';
    return 0;
}