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
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
int st[MAXN][MAXLOG]; 
int lg[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> st[i][0];
    }
    lg[1] = 0;
    for(int i = 2; i <= n; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for(int j = 1; j <= lg[n]; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int len = b - a + 1;
        int k = lg[len];
        int ans = min(st[a][k], st[b - (1 << k) + 1][k]);
        cout << ans << "\n";
    }
    return 0;
}