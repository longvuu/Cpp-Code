/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
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
    for(int i=0;i<n;i++) cin >> a[i];
    int m; 
    cin >> m;
    vector<ll> b(m);
    for(int j=0;j<m;j++) cin >> b[j];
    sort(b.begin(), b.end());
    ll res = 0;
    for(ll x : a){
        auto it = lower_bound(b.begin(), b.end(), x);
        ll t = (ll)4e18;
        if(it != b.end()) t = min(t, llabs(*it - x));
        if(it != b.begin()){
            it--;
            t = min(t, llabs(*it - x));
        }
        res = max(res, t);
    }
    cout << res;
    return 0;
}