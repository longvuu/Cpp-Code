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

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + A[i - 1];
    }

    int res = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int s1 = s[i] * (-1) + (s[n] - s[i]);
        int s2 = s[i] + (s[n] - s[i]) * (-1);
        res = max(res, max(s1, s2));
    }

    cout << res << endl;
    return 0;
}