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
int n, q;
vector<int> a;
vector<int> f(1e6 + 1, 0);
vector<int> p(1e6 + 1, 0);
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }
    
    for (int i = 1; i <= 1e6; ++i) {
        for (int j = i; j <= 1e6; j += i) {
            p[i] += f[j];
        }
    }
    
    for (int i = 1; i <= 1e6; ++i) {
        p[i] += p[i - 1];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << p[R] - p[L - 1] << '\n';
    }
    
    return 0;
}