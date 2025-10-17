/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "INCSEQK"
#define ll unsigned long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int T = 1;
    if (!(cin >> T)) return 0;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        vector< vector<ll> > dp(k + 1, vector<ll>(n, 0ULL));
        for (ll i = 0; i < n; i++) dp[1][i] = 1ULL;
        for (ll i = 2; i <= k; i++) {
            for (ll j = 0; j < n; j++) {
                ll s = 0ULL;
                for (ll p = 0; p < j; p++) if (a[p] < a[j]) s += dp[i - 1][p];
                dp[i][j] = s;
            }
        }
        ll res = 0ULL;
        for (ll i = 0; i < n; i++) res += dp[k][i];
        cout << res << '\n';
    }
    return 0;
}
