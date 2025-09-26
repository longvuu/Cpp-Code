#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;

struct Fenwick {
    int n; vector<ll> bit;
    Fenwick(): n(0) {}
    Fenwick(int n) { init(n); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int idx, ll delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
    ll sumPrefix(int idx) const {
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    ll sumRange(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

static inline void print_int128(__int128 x) {
    if (x == 0) { cout << 0; return; }
    if (x < 0) { cout << '-'; x = -x; }
    string s; s.reserve(40);
    while (x > 0) { int d = (int)(x % 10); s.push_back(char('0' + d)); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n, q; 
    if(!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1);
    Fenwick bit_sum(n), bit_sq(n);

    int i = 1;
    while (i <= n) {
        cin >> a[i];
        bit_sum.add(i, a[i]);
        bit_sq.add(i, a[i] * a[i]);
        i++;
    }

    int qi = 0;
    while (qi < q) {
        int type; cin >> type;
        if (type == 1) {
            int x; ll v; cin >> x >> v;
            ll old = a[x];
            ll dv = v - old;
            ll d2 = v * v - old * old;
            a[x] = v;
            bit_sum.add(x, dv);
            bit_sq.add(x, d2);
        } else if (type == 2) {
            int l, r; cin >> l >> r;
            ll s = bit_sum.sumRange(l, r);
            ll sq = bit_sq.sumRange(l, r);
            __int128 ans = (__int128)s * s - (__int128)sq; 
            ans /= 2;
            print_int128(ans);
            if (qi + 1 < q) cout << '\n';
        }
        qi++;
    }
    
    return 0;
}