/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<array<ll, 3>> s(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
    vector<ll> d(n + 1, 0);
    while(k--) {
        int x, y;
        cin >> x >> y;
        for(int i = x; i <= y; i++) {
            int l = s[i][0], r = s[i][1];
            ll v = s[i][2];
            d[l] += v;
            if(r + 1 <= n) d[r + 1] -= v;
        }
    }
    for(int i = 1; i <= n; i++) {
        d[i] += d[i-1];
        a[i] += d[i];
        cout << a[i] << " ";
    }
    
    return 0;
}