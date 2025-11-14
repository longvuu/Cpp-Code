#include<bits/stdc++.h>
#define ll long long
const int Mod=1e9+7;
using namespace std;
int n;
ll l,r,a[100010],res,g=LLONG_MIN;
ll x(ll m)
{
    ll res=LLONG_MAX;
    for(int i=1;i<=n;i++)
        res=min(res,abs(m-a[i]));
    return res;
}
void trau()
{
    for(ll i=l;i<=r;i++)
    {
        ll k=x(i);
        if(k>=g)
        {
            g=k;
            res=i;
        }
    }
    cout<<res;
}
void full()
{
    while(l<=r)
    {
        ll m=(l+r)/2;
        ll k=x(m);
        if(k>=g)
        {
            g=k;
            res=m;
            l=m+1;
        }
        else
            r=m-1;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("maxdis.inp","r"))
    {
        freopen("maxdis.inp","r",stdin);
        freopen("maxdis.out","w",stdout);
    }
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(r-l+1<=(ll)1e6)
        trau();
    else
        full();
    return 0;
}
/*

*/
