#include<bits/stdc++.h>
#define ll long long
#define db double
const int M=1e9+7;
using namespace std;
int n;
ll a[200010],f[200010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("chiakeo.inp","r"))
    {
        freopen("chiakeo.inp","r",stdin);
        freopen("chiakeo.out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    ll res=LLONG_MAX;
    for(int i=1;i<=n;i++)
        res=min(res,abs(f[n]-f[i]-f[i]));
    cout<<res;
    return 0;
}
