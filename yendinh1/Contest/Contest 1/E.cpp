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

bool check(const vector<int>& a1, const vector<int>& b1) {
    for (int i = 0; i < 52; ++i) {
        if (a1[i] != b1[i]) return false;
    }
    return true;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n > m) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a1(52, 0), b1(52, 0);
    auto g = [](char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        return c - 'A' + 26;
    };

    for (int i = 0; i < n; ++i) {
        a1[g(a[i])]++;
        b1[g(b[i])]++;
    }
    int res = 0;
    if (check(a1, b1)) res++;

    for (int i = n; i < m; ++i) {
        b1[g(b[i])]++;
        b1[g(b[i - n])]--;
        if (check(a1, b1)) res++;
    }
    cout << res << endl;
    return 0;
}