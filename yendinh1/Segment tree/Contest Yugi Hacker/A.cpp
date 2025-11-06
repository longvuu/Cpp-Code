/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, q;
vector<ll> a;
vector<ll> seg;

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

void update(int p, int l, int r, int idx, ll val) {
    if (l == r) {
        seg[p] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (idx <= m) update(p<<1, l, m, idx, val);
    else update(p<<1|1, m+1, r, idx, val);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    return min(query(p<<1, l, m, ql, qr), query(p<<1|1, m+1, r, ql, qr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    a.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    seg.assign(4*n + 5, LLONG_MAX);
    build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x; ll v;
            cin >> x >> v;
            update(1, 1, n, x, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}