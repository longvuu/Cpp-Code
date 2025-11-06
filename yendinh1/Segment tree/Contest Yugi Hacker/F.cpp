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
int n, m;
vector<ll> a;
vector<ll> seg, lz;
void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

void apply(int p, ll val) {
    seg[p] += val;
    lz[p] += val;
}

void push(int p) {
    if (lz[p] != 0) {
        apply(p<<1, lz[p]);
        apply(p<<1|1, lz[p]);
        lz[p] = 0;
    }
}

void range_add(int p, int l, int r, int ql, int qr, ll val) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        apply(p, val);
        return;
    }
    int mid = (l + r) >> 1;
    push(p);
    range_add(p<<1, l, mid, ql, qr, val);
    range_add(p<<1|1, mid+1, r, ql, qr, val);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

ll range_min(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[p];
    int mid = (l + r) >> 1;
    push(p);
    return min(range_min(p<<1, l, mid, ql, qr), range_min(p<<1|1, mid+1, r, ql, qr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    if (!(cin >> n)) return 0;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    string line;
    getline(cin, line); 

    seg.assign(4*n + 5, LLONG_MAX/4);
    lz.assign(4*n + 5, 0);
    build(1, 0, n-1);

    for (int i = 0; i < m; ++i) {
        if (!getline(cin, line)) break;
        if (line.empty()) { --i; continue; }
        istringstream iss(line);
        vector<ll> tok;
        ll x;
        while (iss >> x) tok.push_back(x);
        if (tok.size() == 2) {
            int lf = (int)tok[0], rg = (int)tok[1];
            if (lf <= rg) {
                cout << range_min(1, 0, n-1, lf, rg) << '\n';
            } else {
                cout << min(range_min(1, 0, n-1, lf, n-1), range_min(1, 0, n-1, 0, rg)) << '\n';
            }
        } else if (tok.size() == 3) {
            int lf = (int)tok[0], rg = (int)tok[1];
            ll v = tok[2];
            if (lf <= rg) {
                range_add(1, 0, n-1, lf, rg, v);
            } else {
                range_add(1, 0, n-1, lf, n-1, v);
                range_add(1, 0, n-1, 0, rg, v);
            }
        }
    }

    return 0;
}