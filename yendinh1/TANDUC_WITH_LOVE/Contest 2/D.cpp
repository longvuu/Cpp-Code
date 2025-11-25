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
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

ll BFS(int x, int y, int m, int n,vector<vector<ll>> &a,vector<vector<int>> &visit,int k) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visit[x][y] = k + 1;
    ll dem = 0;
    unordered_set<ll> ss;
    ss.reserve(16);
    while(!q.empty()){
        auto u = q.front(); q.pop();
        int x = u.fi, y = u.se;
        dem++;
        ss.insert(a[x][y]);
        for(int t=0;t<4;t++){
            int nx = x + dx[t];
            int ny = y + dy[t];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] != k) continue;
            visit[nx][ny] = k + 1;
            q.push({nx,ny});
        }
    }
    if(ss.size() >= 2) return dem;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int m,n;
    cin >> m >> n;
    vector<vector<ll>> a(m, vector<ll>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    unordered_map<ll, vector<int>> b;
    b.reserve(m*n*2);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            b[a[i][j]].pb(i * n + j);

    ll res = 0;
    for(int i=1;i<=30;i++){
        unordered_set<ll> mp;
        mp.reserve(b.size() * 2);
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int k = 1;
        for(auto &j:b){
            ll l = j.fi;
            if(mp.count(l)) continue;
            vector<ll> c;
            ll v = l;
            while(v<=1e18){
                if(b.find(v) == b.end()) break;
                c.pb(v);
                mp.insert(v);
                if(i==1){
                    break;
                }
                if(v>1e18/i) break;
                v *= i;
            }
            if(c.size() < 2) continue; 
            vector<int> d;
            d.reserve(1024);
            for(ll val:c){
                auto &vec = b[val];
                d.insert(d.end(), vec.begin(), vec.end());
            }
            if(d.size() <= res) continue;
            k++;
            for(int id:d){
                int x = id / n;
                int y = id % n;
                visit[x][y] = k; 
            }
            for(int id:d){
                int x = id / n;
                int y = id % n;
                if(visit[x][y] != k) continue;
                ll dem = BFS(x, y, m, n, a, visit, k);
                res = max(res, dem);
            }
            k += 2; 
        }
    }
    cout << res;
    return 0;
}