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
const ll N = 3e3 + 10;
ll n, K, a[N];
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> K;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll nhon = 0, vuong = 0, tu = 0;
    for (ll i = 1; i <= n - 2; i++) {
        ll l = i + 2, r = i + 2, lim = i + 2;
        for (ll j = i + 1; j <= n - 1; j++) {
            while (l <= n && a[l] * a[l] < a[i] * a[i] + a[j] * a[j]) l++;
            while (r <= n && a[r] * a[r] <= a[i] * a[i] + a[j] * a[j]) r++;
            while (lim <= n && a[lim] < a[i] + a[j]) lim++;
            nhon += l - j - 1;
            vuong += r - l;
            tu += lim - r;
        }
    }
    if (K == 1) cout << nhon;
    if (K == 2) cout << vuong;
    if (K == 3) cout << tu;
    return 0;
}
