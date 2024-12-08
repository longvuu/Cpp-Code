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
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n-1);
    for(int i = 0; i < n-1; i++) {
        cin >> edges[i].fi >> edges[i].se;
    }
    
    // Assign even numbers from 2 to 2n to vertices
    for(int i = 1; i <= n; i++) {
        cout << i * 2 << " ";
    }
    cout << "\n";
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}