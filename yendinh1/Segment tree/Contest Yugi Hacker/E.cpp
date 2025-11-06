/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
int n, q;
vector<ll> a, seg, lazyA, lazyB;
ll sumRangeIdx(int L, int R) {
    ll len = R - L + 1;
    return (ll)(L + R) * len / 2;
}
void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(p<<1, l, m);
    build(p<<1|1, m+1, r);
    seg[p] = seg[p<<1] + seg[p<<1|1];
}
void apply(int p, int l, int r, ll A, ll B) {
    ll len = r - l + 1;
    seg[p] += A * sumRangeIdx(l, r) + B * len;
    lazyA[p] += A;
    lazyB[p] += B;
}

void push(int p, int l, int r) {
    if (lazyA[p] == 0 && lazyB[p] == 0) return;
    int m = (l + r) >> 1;
    apply(p<<1, l, m, lazyA[p], lazyB[p]);
    apply(p<<1|1, m+1, r, lazyA[p], lazyB[p]);
    lazyA[p] = lazyB[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, ll A, ll B) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        apply(p, l, r, A, B);
        return;
    }
    int m = (l + r) >> 1;
    push(p, l, r);
    update(p<<1, l, m, ql, qr, A, B);
    update(p<<1|1, m+1, r, ql, qr, A, B);
    seg[p] = seg[p<<1] + seg[p<<1|1];
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    push(p, l, r);
    return query(p<<1, l, m, ql, qr) + query(p<<1|1, m+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    if (!(cin >> n)) return 0;
    a.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    seg.assign(4*n + 5, 0);
    lazyA.assign(4*n + 5, 0);
    lazyB.assign(4*n + 5, 0);
    build(1, 1, n);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            ll A = 1;
            ll B = 1 - (ll)l;
            update(1, 1, n, l, r, A, B);
        } else {
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}