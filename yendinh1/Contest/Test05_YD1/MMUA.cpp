/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MMUA"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,m,k; 
vector<ll> x, y, z;
void TRAU(){
    vector<vector<ll>> g(n+1);
    for(ll i=0;i<m;i++){
        ll u=x[i], v=y[i], c=z[i];
        if(c>k){ 
            g[u].pb(v); 
            g[v].pb(u); 
        }
    }
    vector<int> vis(n+1,0);
    ll res=0;
    for(ll i=1;i<=n;i++) if(!vis[i]){
        res++;
        queue<ll> q; 
        q.push(i); 
        vis[i]=1;
        while(!q.empty()){
            ll u=q.front(); 
            q.pop();
            for(ll v:g[u]) 
                if(!vis[v]){ 
                    vis[v]=1; 
                    q.push(v);
            }    
        }
    }
    cout<<res<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin>>n>>m>>k;
    x.resize(m); y.resize(m); z.resize(m);
    for(ll i=0;i<m;i++){ 
        ll u,v,c; 
        cin>>u>>v>>c; 
        x[i]=u; y[i]=v; z[i]=c; 
    }
    TRAU();
    return 0;
}