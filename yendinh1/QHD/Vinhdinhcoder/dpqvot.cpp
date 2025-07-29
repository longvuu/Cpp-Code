/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpqvot"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<long long> dp(n);
    dp[0] = b[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        int j = i-1;
        while (j >= 0 && a[i] - a[j] < k) j--;
        long long k = b[i];
        if (j >= 0) k += dp[j];
        if (k > dp[i]) dp[i] = k;
    }
    cout << dp[n-1] << endl;
    return 0;
}
