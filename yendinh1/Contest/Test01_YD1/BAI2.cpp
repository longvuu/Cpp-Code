/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<ll, ll> mp;
    ll res = 0, l = 1, r = 1, k = 1;
    for(ll i = 1, j = 1; i <= n; i++) {
        if(mp.count(a[i]) && mp[a[i]] >= j) {
            j = mp[a[i]] + 1;
        }
        mp[a[i]] = i;
        if(i - j + 1 > res) {
            res = i - j + 1;
            l = j;
            r = i;
            k = l;
        }
    }
    cout << k << " " << res << endl;
    return 0;
}