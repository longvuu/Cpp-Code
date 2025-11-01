/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "waiting"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5;
int a[N + 5];
int b[N + 5];
int c[N + 5];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> c[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= m; i++){
        int x = upper_bound(b + 1, b + n + 1, c[i]) - b;
        if(x > n)
            cout << -1 << "\n";
        else
            cout << max(0, a[x] - c[i]) << "\n";
    }
    return 0;
}