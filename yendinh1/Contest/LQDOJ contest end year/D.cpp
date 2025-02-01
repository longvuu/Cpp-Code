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

int n;
vector<int> a;
map<int, int> parent;
vector<pair<int, pair<int, int>>> edges;

int find(int x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x;
    }
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin >> n;
    a.resize(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        parent[i] = i;  // Initialize parent in map
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int cost = min(a[i] % a[j], a[j] % a[i]);
            edges.pb({cost, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());
    ll total_cost = 0;
    for(auto e : edges) {
        int cost = e.fi;
        int u = e.se.fi;
        int v = e.se.se;
        
        if(find(u) != find(v)) {
            unite(u, v);
            total_cost += cost;
        }
    }
    
    cout << total_cost;
    return 0;
}