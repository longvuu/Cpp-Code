#include<bits/stdc++.h>
#define ll long long
#define db double
const int M=65536;
using namespace std;
ll seed,mul,add,a[250010];
int k,n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("median.inp","r"))
    {
        freopen("median.inp","r",stdin);
        freopen("median.out","w",stdout);
    }
    cin>>seed>>mul>>add>>n>>k;
    a[1]=seed;
    for(int i=2;i<=n;i++)
        a[i]=(a[i-1]*mul+add)%M;
    ll res=0;
    for(int i=1;i<=n-k+1;i++)
    {
        vector<ll>v;
        for(int j=i;j<=i+k-1;j++)
            v.push_back(a[j]);
        sort(v.rbegin(),v.rend());
        res+=v[(k+1)/2-1];
    }
    cout<<res;
    return 0;
}
