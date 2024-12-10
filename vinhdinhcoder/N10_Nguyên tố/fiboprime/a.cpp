/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "fiboprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

vector<ll> fib;
void fibo(ll limit) {
    fib.pb(0);
    fib.pb(1);
    ll a = 0, b = 1;
    while (b <= limit) {
        ll c = a + b;
        if (c > limit) break;
        fib.pb(c);
        a = b;
        b = c;
    }
}

bool snt(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

bool tk(ll n) {
    return binary_search(fib.begin(), fib.end(), n);
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a, b;
    cin >> a >> b;
    fibo(b);
    ll res = 0;
    for(ll x : fib) {
        if(x >= a && x <= b && snt(x)) {
            res++;
        }
    }
    cout << res;
    return 0;
}
