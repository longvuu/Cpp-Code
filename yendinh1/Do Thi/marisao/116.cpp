/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
ll n, m;
vector<ll> a[N];
int dista[N];
void bfs(ll s) {
    for (int i = 1; i <= n; i++) dista[i] = -1;
    queue<ll> q;
    dista[s] = 0;
    q.push(s);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll v : a[u]) {
            if (dista[v] == -1) {
                dista[v] = dista[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    cin >> n >> m;
    for(ll i = 1; i <= m;i++){
        ll x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    bfs(1);
    for (int i = 2; i <= n;i++){
        if (i > 2) cout << ' ';
        cout << dista[i];
    }
    return 0;
}