/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "doancon"
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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<ll> ans(n, 1);
        if(n > 0) ans[n-1] = 1;
        for(ll i = n - 2; i >= 0; --i) {
            if(a[i] != 0 && a[i+1] != 0 && ((a[i] > 0) != (a[i+1] > 0))) {
                ans[i] = ans[i+1] + 1;
            } else {
                ans[i] = 1;
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}