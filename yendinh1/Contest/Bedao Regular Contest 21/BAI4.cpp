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

const int N = 1e5 + 5;
vector<pair<int, bool>> g[N];
bool vis[N];
int c[N];

bool f(int u, int cl) {
    vis[u] = 1;
    c[u] = cl;
    
    for(auto [v, s] : g[u]) {
        if(!vis[v]) {
            if(!f(v, s ? cl : 1-cl)) return 0;
        } else {
            if((c[v] == c[u]) != s) return 0;
        }
    }
    return 1;
}

void sol() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
    }
    
    for(int d = 1; d <= q; d++) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int x, k;
            cin >> x >> k;
            g[x].pb({0, k == 0});
            g[0].pb({x, k == 0});
        }
        else if(t == 2) {
            int x, y, k;
            cin >> x >> y >> k;
            g[x].pb({y, k == 0});
            g[y].pb({x, k == 0});
        }
        else {
            int x, u, y, v;
            cin >> x >> u >> y >> v;
            int d = ++n;
            g[x].pb({d, u == 0});
            g[d].pb({x, u == 0});
            g[y].pb({d, v == 0});
            g[d].pb({y, v == 0});
        }
        
        memset(vis, 0, sizeof(vis));
        bool p = 1;
        for(int i = 0; i <= n; i++) {
            if(!vis[i] && !g[i].empty()) {
                if(!f(i, 0)) {
                    p = 0;
                    break;
                }
            }
        }
        
        if(!p) {
            cout << d << "\n";
            return;
        }
    }
    cout << "-1\n";
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
    while(t--) sol();
    
    return 0;
}