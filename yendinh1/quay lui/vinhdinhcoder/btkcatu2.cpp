#include<bits/stdc++.h>
#define ll long long
const int N=1e6,Mod=1e9+7;
using namespace std;
int n,sl=-1;
ll m,w[300],v[300],mx=LLONG_MIN;
string rs;
int id[300]; 

string ts(ll x)
{
    string a="";
    while(x!=0)
    {
        a=char(x%10+48)+a;
        x/=10;
    }
    return " "+a;
}

void ql(int i,ll tw,ll tv,string s,int d)
{
    if(tw>m)
        return;
    if(tw<=m&&tw>0)
    {
        if(tv>mx)
        {
            mx=tv;
            if(s[0]==' ')
                s.erase(0,1);
            rs=s;
            sl=d;
        }
    }
    if(i>n)
        return;
    ll rw = m - tw;
    ll mp = tv;
    for(int j=i; j<=n; j++) {
        if(w[j] <= rw) {
            mp += v[j];
            rw -= w[j];
        }
    }
    if(mp <= mx) return;
    if(tw + w[i] <= m)
        ql(i+1,tw+w[i],tv+v[i],s+ts(id[i]),d+1);
    ql(i+1,tw,tv,s,d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("btkcatu2.inp","r"))
    {
        freopen("btkcatu2.inp","r",stdin);
        freopen("btkcatu2.out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    vector<pair<double,int>> it;
    for(int i=1;i<=n;i++)
        it.push_back({(double)v[i]/w[i], i});
    sort(it.begin(),it.end(),greater<pair<double,int>>());
    
    ll nw[300],nv[300];
    for(int i=0;i<n;i++) {
        int x = it[i].second;
        nw[i+1] = w[x];
        nv[i+1] = v[x];
        id[i+1] = x; 
    }
    for(int i=1;i<=n;i++) {
        w[i] = nw[i];
        v[i] = nv[i];
    }
    
    ql(1,0,0,"",0);
    if(sl==-1)
        cout<<0;
    else
        cout<<sl<<'\n'<<rs;
    return 0;
}