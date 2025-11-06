/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;

int n, q;
vector<ll> a, seg, lz;

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(p<<1, l, m);
    build(p<<1|1, m+1, r);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

inline void apply(int p, ll v) {
    seg[p] += v;
    lz[p] += v;
}

inline void push(int p) {
    if (lz[p] != 0) {
        apply(p<<1, lz[p]);
        apply(p<<1|1, lz[p]);
        lz[p] = 0;
    }
}

void update(int p, int l, int r, int ql, int qr, ll val) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        apply(p, val);
        return;
    }
    int m = (l + r) >> 1;
    push(p);
    update(p<<1, l, m, ql, qr, val);
    update(p<<1|1, m+1, r, ql, qr, val);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    push(p);
    return min(query(p<<1, l, m, ql, qr), query(p<<1|1, m+1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    if (!(cin >> n >> q)) return 0;
    a.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    seg.assign(4*n + 5, LLONG_MAX/4);
    lz.assign(4*n + 5, 0);
    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r; ll x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}