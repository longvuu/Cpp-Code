/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    int m, n;
    cin >> st >> m >> n;
    int k = st.size();
    int t1 = 0, t2 = 0, res = k + 1;
    int l = 0;
    for (int r = 0; r < k; r++) {
        if (st[r] == 'A') t1++;
        if (st[r] == 'B') t2++;
        while (t1 >= m && t2 >= n) {
            res = min(res, r - l + 1);
            if (st[l] == 'A') t1--;
            if (st[l] == 'B') t2--;
            l++;
        }
    }
    if (res == k + 1) cout << -1;
    else cout << res;
    return 0;
}