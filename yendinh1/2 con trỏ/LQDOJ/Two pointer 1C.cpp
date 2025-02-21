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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    
    ll dem = 0;
    ll i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ll s1 = 0, s2 = 0;
            ll k = a[i];
            while(i < n && a[i] == k) {
                s1++;
                i++;
            }
            
            while(j < m && b[j] == k) {
                s2++;
                j++;
            }
            dem += s1 * s2;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    
    cout << dem;
    return 0;
}