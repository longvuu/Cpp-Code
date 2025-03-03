/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU5"
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
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll nhon = 0, vuong = 0, tu = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            for(ll k = j + 1; k < n; k++) {
                ll x = a[i], y = a[j], z = a[k];
                if(x > y) swap(x, y);
                if(y > z) swap(y, z);
                if(x > y) swap(x, y);
                if(x + y > z) {
                    if(x * x + y * y > z * z) {
                        nhon++;
                    } else if(x * x + y * y == z * z) {
                        vuong++;
                    } else {
                        tu++;
                    }
                }
            }
        }
    }
    cout << nhon << " " << vuong << " " << tu;
    return 0;
}