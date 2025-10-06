/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "PRIME"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t; 
    cin >> t;
    vector<ll> a(t);
    ll x = 0;
    for(int i = 0; i < t; i++) {
        cin >> a[i];
        x = max(x, a[i]);
    }

    if(x < 72) {
        for(int i = 0; i < t; i++) cout << 0 << '\n';
        return 0;
    }
    int limit = (int)(x / 72) + 10;
    limit = max(limit, 100);
    vector<char> isprime(limit + 1, true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; 1LL * i * i <= limit; i++) {
        if(isprime[i]) {
            for(int j = i * i; j <= limit; j += i) {
                isprime[j] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 2; i <= limit; i++) {
        if(isprime[i]) prime.pb(i);
    }
    vector<int> pi(limit + 1, 0);
    for(int i = 1; i <= limit; i++) {
        pi[i] = pi[i - 1] + (isprime[i] ? 1 : 0);
    }

    for(int tc = 0; tc < t; tc++) {
        ll n = a[tc];
        if(n < 72) {
            cout << 0 << '\n';
            continue;
        }
        ll res = 0;
        for(int r : prime) {
            ll r3 = 1LL * r * r * r;
            if(r3 > n) break;
            for(int q : prime) {
                if(q == r) continue; 
                ll q2 = 1LL * q * q;
                if(r3 * q2 > n) break;
                ll maxp = n / (r3 * q2);
                if(maxp < 2) continue;
                if(maxp > limit) maxp = limit; 
                int cnt = pi[(int)maxp];
                if(r <= maxp) cnt--;
                if(q <= maxp) cnt--;
                if(cnt > 0) res += cnt;
            }
        }
        cout << res << '\n';
    }
    return 0;
}