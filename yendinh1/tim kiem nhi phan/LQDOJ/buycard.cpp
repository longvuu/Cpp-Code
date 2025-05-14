/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/buycard
*/
#include <bits/stdc++.h>
#define taskname ""
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

    int t;
    cin >> t;
    while (t--) {
        ll c, p, n1, n2, t1, t2;
        cin >> c >> p >> n1 >> n2 >> t1 >> t2;
        ll res = 0;
        if (p > 0) {
            ll max0 = c / p;
            max0 = min(max0, n1 - 1);
            if (max0 >= 0) res = max(res, max0);
        }
        if (p > 0 && c >= t1 && n1 <= n2 - 1) {
            ll max1 = (c - t1) / p;
            max1 = min(max1, n2 - 1);
            if (max1 >= n1) res = max(res, max1);
        }
        // Đoạn 3: n2 trở lên (thuế t2)
        if (p > 0 && c >= t2) {
            ll max2 = (c - t2) / p;
            if (max2 >= n2) res = max(res, max2);
        }
        cout << res << '\n';
    }
    return 0;
}