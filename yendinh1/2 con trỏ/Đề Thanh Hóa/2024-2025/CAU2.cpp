/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU2"  
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i =0;i<n;i++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a.begin(), a.end());
    ll res=1;
    for (ll i =1;i<n;i++) {
        if (a[i].se<a[i-1].se){
            res++;
        }
    }

    cout << res << endl;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    solve();
    return 0;
}