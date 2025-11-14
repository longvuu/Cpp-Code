#include<bits/stdc++.h>
#define ll long long
const int Mod=1e9+7;
using namespace std;
ll a,b;
int cnt(ll n)
{
    int d=0;
    while(n>0)
    {
        if(n%10==0)
            d++;
        else
            return d;
        n/=10;
    }
}
void trau()
{
    ll res=1;
    int l=a,r=b;
    for(int i=(int)l;i<=(int)r;i++)
        res=res*i/__gcd(res,1ll*i);
    cout<<res<<' '<<cnt(res);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("zeros.inp","r"))
    {
        freopen("zeros.inp","r",stdin);
        freopen("zeros.out","w",stdout);
    }
    cin>>a>>b;
    trau();
    return 0;
}
/*

*/
