/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkcow1"
using namespace std;
int n, M, a[25];
int res = 0, minCow = 1e9;

void Try(int i, int sum, int cnt) {
    if (sum > M) return;
    if (i > n) {
        if (sum == M) {
            res++;
            minCow = min(minCow, cnt);
        }
        return;
    }
    Try(i + 1, sum, cnt);
    Try(i + 1, sum + a[i], cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> M;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Try(1, 0, 0);
    cout << res << ' ' << minCow;
    return 0;
}