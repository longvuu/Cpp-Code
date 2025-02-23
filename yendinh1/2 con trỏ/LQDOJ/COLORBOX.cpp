/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int n, cnt = 0;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> n;
    vector<int> a(n), b(n + 1, 0);
    int ans = n, j = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
        if (b[a[i]] == 2) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < n; i++) {
            b[a[i]]--;
            if (b[a[i]] == 1) {
                cnt--;
            }
            while (b[a[j]] < 1 && j <= i) {
                b[a[j]]++;
                j++;
            }
            if (cnt == 0) {
                ans = min(ans, i - j + 1);
            }
        }
        cout << ans;
    }
    return 0;
}