/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MEDIAN"
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
void tinh(multiset<ll>& l, multiset<ll>& r, ll sz) {
    while ((ll)l.size() > sz) {
        auto i = prev(l.end());
        r.insert(*i);
        l.erase(i);
    }
    while ((ll)l.size() < sz && !r.empty()) {
        auto i = r.begin();
        l.insert(*i);
        r.erase(i);
    }
}
void them(multiset<ll>& l, multiset<ll>& r, ll sz, ll x) {
    if (l.empty() || x <= *prev(l.end())) l.insert(x);
    else r.insert(x);
    tinh(l, r, sz);
}
void xoa(multiset<ll>& l, multiset<ll>& r, ll sz, ll x) {
    auto i = l.find(x);
    if (i != l.end()) l.erase(i);
    else {
        i = r.find(x);
        if (i != r.end()) r.erase(i);
    }
    tinh(l, r, sz);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll seed, mul, add, n, k;
    cin >> seed >> mul >> add >> n >> k;
    vector<ll> a(n+1);
    a[1] = seed;
    for(ll i = 2; i <= n; i++) a[i] = (a[i-1]*mul+add)%65536;
    multiset<ll> l, r;
    ll sz = (k+1)/2;
    vector<ll> b(k+1);
    for(ll i = 1; i <= k; i++) {
        b[i%k] = a[i];
        them(l, r, sz, a[i]);
    }
    ll res = *prev(l.end());
    for(ll i = k+1; i <= n; i++) {
        xoa(l, r, sz, b[i%k]);
        b[i%k] = a[i];
        them(l, r, sz, a[i]);
        res += *prev(l.end());
    }
    cout << res << '\n';
    return 0;
}