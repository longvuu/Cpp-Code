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

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
    
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    DSU f(n), g(n);
    set<pair<int,int>> edges_f;
    
    // Read edges for graph F
    for(int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        edges_f.insert({u, v});
        f.unite(u, v);
    }
    
    // Read edges for graph G
    for(int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        g.unite(u, v);
    }
    
    // Count edge operations needed
    int operations = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            bool has_edge = edges_f.count({i, j});
            bool should_connect = g.connected(i, j);
            bool is_connected = f.connected(i, j);
            
            // If connectivity doesn't match what we want
            if(should_connect != is_connected) {
                operations++;
            }
            // If we have an edge but don't need it, or vice versa
            else if(has_edge != should_connect) {
                operations++;
            }
        }
    }
    
    cout << operations/2 << '\n';
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