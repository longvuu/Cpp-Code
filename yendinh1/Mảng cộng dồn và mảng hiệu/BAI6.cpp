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
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), d(n + 1, 0), s(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        d[l]++;
        if(r + 1 < n) {
            d[r + 1]--;
        }
    }
    s[0] = d[0];
    for(int i = 1; i < n; i++) {
        s[i] = s[i-1] + d[i];
    }
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] * s[i];
    }
    
    cout << ans;
    return 0;
}