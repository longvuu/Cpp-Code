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

unordered_map<ll, int> memo;

int dem(ll n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    int count = 0;
    ll sqrt_n = sqrt(n);
    for (ll i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                count += 1;
            } else {
                count += 2;
            }
        }
    }
    memo[n] = count;
    return count;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int T;
    cin >> T;
    vector<ll> a(T);
    for (int i = 0; i < T; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < T; ++i) {
        if (dem(a[i]) == 9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}