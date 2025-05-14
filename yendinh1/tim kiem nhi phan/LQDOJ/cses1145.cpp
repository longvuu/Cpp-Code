/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/cses1145
*/
#include <bits/stdc++.h>
#define taskname ""
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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> s;
    for (ll i = 0; i < n; i++) {
        ll k = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
        if (k == s.size()) {
            s.push_back(a[i]);
        } else {
            s[k] = a[i];
        }
    }
    cout << s.size() << '\n';
    return 0;
}