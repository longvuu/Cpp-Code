/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "semiprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MAX_N = 1000001;
vector<bool> isPrime(MAX_N, true);
vector<ll> primes;
void sangnt() {
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i < MAX_N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (ll i = 2; i < MAX_N; i++) {
        if (isPrime[i]) primes.pb(i);
    }
}

bool check(ll n) {
    for (ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            ll d = n / primes[i];
            if (isPrime[d]) return true;
        }
    }
    return false;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    sangnt(); 
    ll n;
    ll res = 0;
    cin >> n;
    for (ll i = 2; i <= n; i++) {
        if (check(i)) {
            res += i;
        }
    }
    cout << n << " " << res;
    return 0;
}