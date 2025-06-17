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
int n, a[10000], x[1000];
vector<vector<int>> res;

void quaylui(int i, ll s1, ll s2) {
    if (i == n) {
        if (s1 == s2) res.pb(vector<int>(x, x + n));
        return;
    }
    x[i] = 1;
    quaylui(i + 1, s1 + a[i + 1], s2);
    x[i] = 2;
    quaylui(i + 1, s1, s2 + a[i + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    quaylui(0, 0, 0);
    if (res.empty()) {
        cout << -1;
    } else {
        sort(res.begin(), res.end());
        for (auto &v : res) {
            for (int i = 0; i < n; i++) cout << v[i];
            cout << "\n";
        }
    }
    return 0;
}