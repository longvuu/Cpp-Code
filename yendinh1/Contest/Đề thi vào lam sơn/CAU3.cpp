/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
#define ll long long
#define MOD 1000000007
using namespace std;
vector<int> primes;
void sang(int n) {
    vector<bool> is_prime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
ll dem(ll N, ll p) {
    ll res = 0;
    for (ll x = p; x <= N; x *= p)
        res += N / x;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    sang(100005);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 1;
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            if (p > n) break;
            ll cnt = dem(n, p);
            cnt = (cnt / 3) * 3;
            if (cnt > 0) {
            for (ll j = 0; j < cnt; j++) {
                ans = (ans * p) % MOD;
            }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}