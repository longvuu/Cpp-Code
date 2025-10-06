/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "NUMMAX"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool check(string a, string b) {
    int pa = 0, pb = 0;
    while(pa < a.length() && a[pa] == '0') pa++;
    while(pb < b.length() && b[pb] == '0') pb++;
    if(pa == a.length()) a = "0";
    else a = a.substr(pa);
    if(pb == b.length()) b = "0";
    else b = b.substr(pb);
    if(a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a > b;
}
int main() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if(check(dp[i][j-1], dp[i][j])) {
                dp[i][j] = dp[i][j-1];
            }
            if(a[i-1] == b[j-1]) {
                string s = dp[i-1][j-1] + a[i-1];
                if(check(s, dp[i][j])) {
                    dp[i][j] = s;
                }
            }
        }
    }
    string res = dp[n][m];
    int i = 0;
    while(i < res.length() && res[i] == '0') {
        i++;
    }
    
    if(i == res.length()) {
        cout << "0";
    } else {
        cout << res.substr(i);
    }
    
    return 0;
}