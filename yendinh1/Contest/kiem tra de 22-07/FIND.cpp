/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "FIND"
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
    vector<pair<ll, int>> a; 
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a.pb({x, 1}); 
        a.pb({y, -1}); 
    }
    sort(a.begin(), a.end());
    ll res = 0;
    ll l = 0;
    int dem = 0;
    for (auto i : a) {
        ll k = i.fi;
        int t = i.se;
        if (dem == 0 && t == 1) {
            l = k;
        }
        dem += t;
        if (dem == 0) {
            res = max(res, k - l);
        }
    }
    
    cout << res << endl;
    
    return 0;
}