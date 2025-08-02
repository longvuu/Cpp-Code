/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".INP").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".INP").c_str(), "r", stdin);
        freopen((string(taskname) + ".OUT").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> dp(n, 1);
    int res = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i;j++) {
            if(a[i] % a[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << '\n';
    return 0;
}