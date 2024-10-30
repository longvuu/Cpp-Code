/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

#define N 100003
#define mod 1000000007
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int>
#define INF 1e18
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define MAX_A 100003 // Assuming the maximum value of a[i] is less than MAX_A

int n, q, a[N], times = 0, in[N], ans[N], sz[N], st[N];
vector<int> g[N];
vector<pii> qr[N];
ll cnt[MAX_A]; // Fixed-size array for counts

struct FenTree{

    int bit[N];

    void init()
    {
        fill(bit, bit + N, 0);
    }

    void upd(int x, int val)
    {
        for( ; x < N; x += x & -x) bit[x] += val;
    }

    int get(int x)
    {
        int ans = 0;
        for( ; x ; x -= x & -x) ans += bit[x];
        return ans;
    }

} fen;

void dfs(int u, int p)
{
    in[u] = ++times; 
    st[times] = a[u];
    sz[u] = 1;
    for(auto v : g[u])
    {
        if (v != p) 
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
        
void Sack(int u, int p, bool keep)
{
    int child = 0;
    for(auto v : g[u])
    {
        if (v != p && (!child || sz[v] > sz[child])) 
            child = v;
    }
    for(auto v : g[u])
    {
        if (v != p && v != child) 
            Sack(v, u, 0);
    }
    if (child) Sack(child, u, 1);
    
    // Increment count for the current node
    ++cnt[a[u]];
    
    // Update counts for the subtree
    for(auto v : g[u])
    {
        if (v != p && v != child)
        {
            for(int i = in[v]; i < in[v] + sz[v]; ++i) 
                ++cnt[st[i]];
        }
    }
    
    fen.init(); // Initialize Fenwick Tree
    for(int i = 0; i < MAX_A; ++i) // Update Fenwick Tree
    {
        if (cnt[i] > 0) // Only update for non-zero counts
            fen.upd(cnt[i], 1);
    }
    
    // Process queries for the current node
    for(auto x : qr[u])
    {
        ans[x.se] = fen.get(N) - fen.get(x.fi - 1);
    }
    
    if (!keep) 
    {
        fill(cnt, cnt + MAX_A, 0); // Clear the cnt array
    }
}

void Proc()
{
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    FOR(i, 1, q)
    {
        int u, x;
        cin >> u >> x;
        qr[u].pb({x, i});
    }
    Sack(1, 0, 1);
    FOR(i, 1, q) cout << ans[i] << '\n';
}

int32_t main() {
    int T; T = 1;
    //cin >> T;
    while (T--) Proc();
}
