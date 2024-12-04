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
    if(fopen("sk11a.txt", "r") != NULL) {
        freopen("sk11a.txt", "r", stdin);
        freopen("thongke.txt", "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll s=0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        s+=a[i];
    }
    cout << 1.0*s/n;
    return 0;
}