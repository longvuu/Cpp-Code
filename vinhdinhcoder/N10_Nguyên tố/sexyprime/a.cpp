/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "sexyprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

const int MAX = 1000000;
vector<bool> isPrime(MAX + 1, true);
vector<pair<ll, ll>> a;

void sangnt() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(ll i = 2; i <= MAX-6; i++) {
        if(isPrime[i] && isPrime[i+6]) {
            a.pb({i, i+6});
        }
    }
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    sangnt();
    ll t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        k--;\
        cout << a[k].fi << " " << a[k].se << "\n";
    }
    return 0;
}