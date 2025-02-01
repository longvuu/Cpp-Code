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
    vector<vector<int>> cows(n);
    vector<int> pos(n, 0); // Current position in each cow's deck
    
    for(int i = 0; i < n; i++) {
        cows[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> cows[i][j];
        }
        sort(cows[i].begin(), cows[i].end());
    }
    
    vector<int> order(n); // Final order of cows
    vector<bool> used(n, false);
    int last = -1;
    
    // For each position in the permutation
    for(int i = 0; i < n; i++) {
        int best_cow = -1;
        int min_card = INT_MAX;
        
        // Find the cow with smallest valid card
        for(int cow = 0; cow < n; cow++) {
            if(used[cow]) continue;
            if(pos[cow] >= m) continue;
            
            int card = cows[cow][pos[cow]];
            if(card > last && card < min_card) {
                min_card = card;
                best_cow = cow;
            }
        }
        
        if(best_cow == -1) {
            cout << "-1\n";
            return;
        }
        
        order[i] = best_cow + 1;
        used[best_cow] = true;
        last = cows[best_cow][pos[best_cow]];
        pos[best_cow]++;
    }
    
    // Verify remaining rounds
    for(int round = 1; round < m; round++) {
        for(int i = 0; i < n; i++) {
            int cow = order[i] - 1;
            if(pos[cow] >= m || cows[cow][pos[cow]] <= last) {
                cout << "-1\n";
                return;
            }
            last = cows[cow][pos[cow]];
            pos[cow]++;
        }
    }
    
    // Print solution
    for(int x : order) cout << x << " ";
    cout << "\n";
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
    while (t--) solve();
    
    return 0;
}