/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

const int MAXN = 105;
const int MAXVAL = 1e5 + 5;
pair<int, int> ar[MAXN];
ll dp[MAXN][MAXVAL]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int N, W;
    cin >> N >> W;
    int grtVal = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> ar[i].fi >> ar[i].se;
        grtVal += ar[i].se;
    }
    for (int i = 0; i <= N; ++i)
        for (int v = 0; v <= grtVal; ++v)
            dp[i][v] = W + 1;
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = 0;
        for (int v = 1; v <= grtVal; ++v) {
            dp[i][v] = dp[i-1][v];
            if (v >= ar[i].se)
                dp[i][v] = min(dp[i][v], dp[i-1][v - ar[i].se] + ar[i].fi);
        }
    }

    int ans = 0;
    for (int v = 1; v <= grtVal; ++v)
        if (dp[N][v] <= W)
            ans = v;

    cout << ans;
    
    return 0;
}