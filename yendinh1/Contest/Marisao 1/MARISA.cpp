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
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> s;
    vector<ll> refs;
    for(ll i = 0; i < n; i++) {
        if(a[i] > 0) {
            s.insert(a[i]);
            refs.pb(a[i]);
        }
    }

    ll dem = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] == 0) dem++;
        else if(a[i] > dem) {
            cout << -1 << endl;
            return 0;
        }
    }
    if(!refs.empty()) {
        sort(refs.begin(), refs.end());
        if(refs[0] != 1) {
            cout << -1 << endl;
            return 0;
        }
        for(ll i = 1; i < refs.size(); i++) {
            if(refs[i] - refs[i-1] > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    ll res = 0;
    ll k = 0;
    vector<bool> check(n + 1, false);
    for(ll i = 0; i < n; i++) {
        if(a[i] > 0 && !check[a[i]]) {
            check[a[i]] = true;
            res++;
        }
    }
    for(ll pos : s) {
        if(pos > k) {
            res += (pos - k);
            k = pos;
        }
    }
    
    cout << res << endl;
    return 0;
}