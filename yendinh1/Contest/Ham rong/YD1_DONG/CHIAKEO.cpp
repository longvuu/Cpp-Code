#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[200005],s[200005];
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	freopen("CHIAKEO.INP","r",stdin);
    freopen("CHIAKEO.OUT","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	ll kq=1e18;
	for(int i=1;i<=n;i++)
	{
		ll a=s[i];
		ll b=s[n]-a;
		kq=min(kq,abs(a-b));
	}
	cout<<kq;
	return 0;
}
