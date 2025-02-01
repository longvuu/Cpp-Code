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
    ll n, M;
    cin >> n >> M;
    vector<ll> a(n+1);
    vector<ll> s(n+1,0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    sort(a.begin() + 1, a.end());
    ll res = 0;
    ll j = n;
    for (ll i = 1; i <= n; i++) {
        while (j > 0 && a[i] + 2 * a[j] > M) {
            j--;
        }
        res += j;
    }
    cout << res;
    return 0;
}