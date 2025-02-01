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
vector<int> freq(1e6 + 1, 0);
vector<int> prefix(1e6 + 1, 0);

void preprocess() {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                freq[j]++;
                if (j != a[i] / j) {
                    freq[a[i] / j]++;
                }
            }
        }
    }
    for (int i = 1; i <= 1e6; ++i) {
        prefix[i] = prefix[i - 1] + freq[i];
    }
}

int query(int L, int R) {
    return prefix[R] - prefix[L - 1];
}

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
    }
    
    preprocess();
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << '\n';
    }
    
    return 0;
}