/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/gttb
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i-1];
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m == 0) {
                l = m + 1;
                continue;
            }
            if (s[m] < k * m) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}