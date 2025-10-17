#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define inf 999999999
using namespace std;
struct guard
{
    int s, t, c;
};
guard  a[N], tmp[N];
int leaf[N];
ll TreeMin[4*N], dp[N];
int n, m;
ll result = inf;
bool cmp(guard X, guard Y)
{
    return X.t < Y.t;
}
void build(int p, int l, int r)
{
    if (l==r)
    {
        TreeMin[p]=tmp[l].c;
        leaf[l] = p;
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p+1, mid +1, r);
    TreeMin[p]= min(TreeMin[2*p],TreeMin[2*p+1]);
}
void update(int p, int x)
{
    int i = leaf[p];
    TreeMin[i] = x;
    while (i>1)
    {
        i/=2;
        TreeMin[i]= min(TreeMin[2*i], TreeMin[2*i +1]);
    }
}
ll findMin(int p, int l, int r, int u, int v)
{
    if (v<l || r<u) return inf;
    if (u<= l && r<=v) return TreeMin[p];
    int mid =(l+r)/2;
    int x=findMin(2*p,l,mid,u,v);
    int y=findMin(2*p+1,mid+1,r,u,v);
    return(min(x,y));
}
int binarySearch(int x, int l, int r)
{
    int res=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (tmp[mid].t < x)
        {
            res=mid;
            l = mid +1;
        }
        else r= mid - 1;
    }
    return res;
}
int main()
{
    freopen("CAU5.INP","r", stdin);
    freopen("CAU5.OUT", "w", stdout);
    cin>>n>>m;
    for (int i=2; i<= m+1; i++)
    cin>>a[i].s>> a[i].t >> a[i].c;
    sort(a+1, a+m+1,cmp);
    m = m+1;
    fill(TreeMin + 1, TreeMin + m +1, inf);
    for(int i=1; i<=m; i++)
        tmp[i].c = inf;
    tmp[1].c =0;
    build(1,1,m);
    int d=1;
    for(int i=2; i<=m ; i++)
    {
        if(a[i].s > tmp[d].t) continue;
        int j= binarySearch(a[i].s,1,d);
        dp[i] = findMin(1,1,m,j+1,d) + a[i].c;
        tmp[++d]=a[i];
        update(d, dp[i]);
        if (a[i].t >=n)
            result = min(result, dp[i]);
    }
    cout<< result;
   return 0;
}
