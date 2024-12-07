/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "primepalin"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
vector<bool> prime(10000000, true);
void sangnt(ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}
bool palin(ll n) {
    ll rev = 0, orig = n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return orig == rev;
}

int simp() {
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    sangnt(10000000);
    while (!prime[n] || !palin(n)) {
        n++;
    }
    cout << n;
    return 0;
}