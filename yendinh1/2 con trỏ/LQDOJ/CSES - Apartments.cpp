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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n),b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    for(ll i = 0, j = 0; i < n; i++) {
        while(j < m && b[j] < a[i] - k) j++;
        if(j < m && b[j] <= a[i] + k) {
            ans++;
            j++;
        }
    }
    cout << ans;
    
    return 0;
}