/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "chons"
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
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0; i < n;i++) {
        for(int j = sum; j >= a[i];j--) {
            if(dp[j - a[i]]) dp[j] = true;
        }
    }

    int res = 0;
    for(int i = 1; i <= sum;i++) {
        if(dp[i]) ++res;
    }
    cout << res << '\n';
    return 0;
}