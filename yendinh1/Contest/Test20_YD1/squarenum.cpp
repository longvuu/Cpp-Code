/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "squarenum"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll MOD = 1000000007;
ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
ll modinv(ll a) { 
    return modpow(a, MOD - 2); 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n; 
    cin >> n;
    ll res = 1;
    for (ll i = 1; i <= n; i++) res = (res * i) % MOD;
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.pb((int)i);
            if (i * i <= n) {
                for (ll j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
    }
    for (int p : primes) {
        bool ok = false;
        ll t = p;
        while (t <= n) {
            ok ^= ((n / t) & 1);
            if (t > n / p) break;
            t *= p;
        }
        if (ok) res = (res * modinv(p)) % MOD;
    }
    cout << res << "\n";
    return 0;
}