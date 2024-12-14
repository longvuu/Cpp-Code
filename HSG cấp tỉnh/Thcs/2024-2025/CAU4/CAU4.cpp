/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<pair<ll, ll>> phantichthuasongto(ll n) {
    vector<pair<ll, ll>> a;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ll dem = 0;
            while (n % i == 0) {
                dem++;
                n /= i;
            }
            a.pb({i, dem});
        }
    }
    if (n > 1) {
        a.pb({n, 1});
    }
    return a;
}

int solve(ll a, ll b) {
    ll k = 1;
    for (ll i = a; i <= b; i++) {
        k = (k * i) % MOD;
    }
    vector<pair<ll, ll>> s = phantichthuasongto(k);
    ll res = 1;
    for (ll i = 0; i < s.size(); i++) {
        res = (res * (2 * s[i].second + 1)) % MOD;
    }
    return res;
}

int simp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}