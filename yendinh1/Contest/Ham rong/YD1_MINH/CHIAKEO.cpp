#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("CHIAKEO.INP","r",stdin);
	freopen("CHIAKEO.OUT","w",stdout);

	int n;
	cin>>n;
	vector<int> a(n+1),p(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]+=p[i-1]+a[i];
	}
	ll kq=LLONG_MAX;
	for(int i=1;i<n;i++)
	{
		ll k=abs(p[n]-2*p[i]);
		kq=min(kq,k);
	}
	cout<<kq;
	return 0;
}
