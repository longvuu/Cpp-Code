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
const int N =1e5+5;
ll n,m;
vector<ll> a[N];
bool visited[N];

void dfs(ll u){
    visited[u]=true;
    for(ll v:a[u]){
        if(!visited[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> m;
    for(ll i =1;i<=m;i++){
        ll x,y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    memset(visited,false,sizeof(visited));
    ll res=0;
    for(ll i =1;i<=n;i++){
        if(!visited[i]){
            res++;
            dfs(i);
        }
    }
    cout << res;
    return 0;
}