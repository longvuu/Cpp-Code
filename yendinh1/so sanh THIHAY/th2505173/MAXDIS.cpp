#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll l,r,n;
ll tinh(const vector<ll> &a,ll x)
{
	auto k=lower_bound(a.begin(),a.end(),x);
	ll d1=1e18;
	if(k!=a.end())
		d1=min(d1,abs(x-*k));
	if(k!=a.begin())
		d1=min(d1,abs(x-*(k--)));
	return d1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("MAXDIS.INP","r",stdin);
    freopen("MAXDIS.OUT","w",stdout);
	cin>>n>>l>>r;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll m=a.size();
	sort(a.begin(),a.end());
	ll b=l;
	ll ma=-1,kq=1;
	ll d1=tinh(a,l);
	ma=d1;
	ll d2=tinh(a,r);
	if(d2>ma)
	{
		ma=d2;
		b=r;
	}
	else if(d2==ma)
		kq=r;
	for(int i=0;i<n;i++)
	{
		ll x=(a[i+1]+a[i])/2;
		if(x>=l && x<=r)
		{
			ll k=x-a[i];
			if(k>ma)
			{
				ma=k;
				kq=x;
			}
			else if(k==ma)
				kq=max(kq,x);
		}
	}
	cout<<kq;
    return 0;
}
