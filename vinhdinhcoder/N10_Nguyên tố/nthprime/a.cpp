/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "nthprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
vector<bool> prime(10000000, true);
vector<ll> primes;
void sangnt(ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.pb(i);
        }
    }
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll t;
    cin >> t;
    sangnt(10000000);
    while(t--) {
        ll n;
        cin >> n;
        cout << primes[n-1] << '\n';
    }
    return 0;
}