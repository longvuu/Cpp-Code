/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "subseq"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    x = abs(x); y = abs(y);
    while (y) { int t = x % y; x = y; y = t; }
    return x;
}
int tinh(int l, int r, vector<int>& g, vector<vector<int>>& s) {
    int d = r - l + 1;
    int k = g[d];
    return gcd(s[k][l], s[k][r - (1<<k) + 1]);
}

bool check(int m, int n, vector<int>& g, vector<vector<int>>& s) {
    if (m == 0) return true;
    for (int i = 0; i + m - 1 < n; i++) {
        int v = tinh(i, i + m - 1, g, s);
        if (v == 0 || v > 1) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            a[i] = llabs(x);
        }
        if(n == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> lg(n+1);
        lg[1] = 0;
        for(int i = 2; i <= n; i++) lg[i] = lg[i>>1] + 1;
        int logv = lg[n] + 1;
        vector<vector<int>> st(logv, vector<int>(n));
        for(int i = 0; i < n; i++) st[0][i] = a[i];
        for(int k = 1; k < logv;k++) {
            int j = 1 << k;
            int h = j >> 1;
            for (int i = 0; i + j - 1 < n; i++) {
                st[k][i] = gcd(st[k-1][i], st[k-1][i+h]);
            }
        }
        int l = 1, r = n, res = 0;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid, n, lg, st)) {
                res = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << res << '\n';
    }
    return 0;
}