/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "TOMED"
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
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll i = n / 2; 
    ll l = a[i];
    ll r = a[i] + k; 
    ll res = l;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll k = 0;
        for (int i = i; i < n; i++) {
            k += max(0LL, mid - a[i]);
        }
        if (k <= k) {
            res = mid; 
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
    
    return 0;
}