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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    ll b;
    cin >> b;
    
    // Try all possible combinations
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<ll> temp = a;
        // Apply operations based on binary mask
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                temp[i] = b - temp[i];
            }
        }
        // Check if resulting array is sorted
        bool sorted = true;
        for(int i = 1; i < n; i++) {
            if(temp[i] < temp[i-1]) {
                sorted = false;
                break;
            }
        }
        if(sorted) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}