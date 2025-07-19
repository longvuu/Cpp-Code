/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkcow2"
using namespace std;

int n, a[25];
vector<vector<int>> ans;
int x[25];

void Try(int i) {
    if (i > n) {
        int sum1 = 0, sum2 = 0;
        for (int j = 1; j <= n; ++j) {
            if (x[j] == 1) sum1 += a[j];
            else sum2 += a[j];
        }
        if (sum1 == sum2) {
            vector<int> tmp;
            for (int j = 1; j <= n; ++j) tmp.push_back(x[j]);
            ans.push_back(tmp);
        }
        return;
    }
    x[i] = 1;
    Try(i + 1);
    x[i] = 2;
    Try(i + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Try(1);
    if (ans.empty()) {
        cout << -1;
    } else {
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int i = 0; i < n; ++i) cout << v[i];
            cout << '\n';
        }
    }
    return 0;
}