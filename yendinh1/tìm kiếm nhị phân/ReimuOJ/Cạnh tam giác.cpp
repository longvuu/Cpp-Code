/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "main"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tknp(vector<ll> a, ll l, ll r, ll x){
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for (ll i = 0; i < n - 2; i++) {
        for (ll j = i + 1; j < n - 1; j++) {
            ll sum = a[i] + a[j];
            ll k = tknp(a, j + 1, n, sum - 1);
            res += (k - j - 1); 
        }
    }
    cout << res << "\n";
    return 0;
}