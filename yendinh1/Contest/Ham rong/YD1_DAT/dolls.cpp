#include<bits/stdc++.h>
#define ll long long
#define db double
const int M=65536;
using namespace std;
int n,kt[100010];
ll k,a[100010],c[100010];
int lobo(int i)
{
    int d=i+1,c=n,j=-1;
    while(d<=c)
    {
        int g=(d+c)/2;
        if(a[i]-a[g]>=k)
        {
            j=g;
            c=g-1;
        }
        else
            d=g+1;
    }
    return j;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("dolls.inp","r"))
    {
        freopen("dolls.inp","r",stdin);
        freopen("dolls.out","w",stdout);
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        c[i]=a[i];int l=-1;
        for(int j=1;j<i;j++)
        {
            if(a[i]-a[j]>=k&&!kt[j])
            {
                if(c[j]+a[i]>=c[i])
                {
                    c[i]=c[j]+a[i];
                    l=j;
                }
            }
        }
        if(l!=-1)
            kt[l]=1;
    }
    ll t=0;
    for(int i=1;i<=n;i++)
        if(!kt[i])
            t+=a[i];
    cout<<t;
    return 0;
}
