/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "demxaudx"
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
    
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for(int i = 1; i <= n; i++) dp[i][i] = true; 
    for(int i = 1; i < n; i++) dp[i][i + 1] = (s[i - 1] == s[i]);
    for(int k = 3; k <= n; k++) { 
        for(int i = 1; i + k - 1 <= n; i++) {
            int j = i + k - 1;
            dp[i][j] = (s[i - 1] == s[j - 1] && dp[i + 1][j - 1]);
        }
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        for(int i = a; i <= b; i++) {
            for(int j = i; j <= b; j++) {
                if(dp[i][j]) res++;
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}