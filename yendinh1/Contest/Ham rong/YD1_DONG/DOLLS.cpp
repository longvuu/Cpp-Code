#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
int main() 
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	freopen("DOLLS.INP","r",stdin);
    freopen("DOLLS.OUT","w",stdout);
    cin>>n>>k;
    vector<ll> a(n),f(n);
    for(int i=0;i<n;i++) 
		cin>>a[i];
    sort(a.begin(),a.end());
    f[0]=a[0];
    for(int i=1;i<n;i++) 
	{
        ll j=lower_bound(a.begin(),a.end(),a[i]-k+1)-a.begin();
        if(j>0)
			f[i]=min(f[i-1]+a[i],f[j-1]+a[i]);
        else 
			f[i]=min(f[i-1]+a[i],a[i]);
    }
    cout<<f[n-1];
    return 0;
}
