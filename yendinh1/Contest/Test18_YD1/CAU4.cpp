/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n, q;
vector<ll> a;
vector<int> x, y, z, s;
void build(int i, int l, int r){
    if(l == r){
        x[i] = 1;
        y[i] = z[i] = s[i] = 0; 
        return;
    }
    int m = (l + r) / 2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    x[i] = x[i*2] + x[i*2+1];
    y[i] = y[i*2];
    z[i] = z[i*2+1];
    s[i] = max(s[i*2], s[i*2+1]);
}

void merge(int i){
    int l = i*2, r = i*2+1;
    x[i] = x[l] + x[r];
    if (y[l] == x[l])
        y[i] = x[l] + y[r];
    else 
        y[i] = y[l];
    if (z[r] == x[r]) 
        z[i] = x[r] + z[l];
    else 
        z[i] = z[r];
    s[i] = max({s[l], s[r], z[l] + y[r]});
}

void query(int i, int l, int r, int pos){
    if(l == r){
        x[i] = 1;
        y[i] = z[i] = s[i] = 1;
        return;
    }
    int m = (l + r) / 2;
    if(pos <= m) query(i*2, l, m, pos);
    else query(i*2+1, m+1, r, pos);
    merge(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    cin >> n >> q;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<pair<ll,int>> p1;
    p1.reserve(n);
    for(int i=1;i<=n;i++) p1.push_back({a[i], i});
    sort(p1.begin(), p1.end());
    vector<pair<ll,int>> p2(q);
    for(int i=0;i<q;i++){
        ll k; 
        cin >> k;
        p2[i] = {k, i};
    }
    sort(p2.begin(), p2.end());
    x.assign(4*n+4,0);
    y.assign(4*n+4,0);
    z.assign(4*n+4,0);
    s.assign(4*n+4,0);
    build(1,1,n);
    vector<int> res(q,0);
    int t = 0;
    for(auto &qq : p2){
        ll k = qq.fi;
        int j = qq.se;
        while(t < n && p1[t].fi <= k){
            query(1,1,n, p1[t].se);
            t++;
        }
        res[j] = s[1];
    }
    for(int i=0;i<q;i++) cout << res[i] << '\n';
    return 0;
}