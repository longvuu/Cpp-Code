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
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int dem = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        int s1 = A[r];
        int s2 = A[r];
        for (int i = r; i >= l; i--) {
            s1 = max(s1, A[i]);
            s2 = min(s2, A[i]);
            if (s1 - s2 <= k) {
                dem++;
            } else {
                l = i + 1;
                break;
            }
        }
    }

    cout << dem;
    return 0;
}