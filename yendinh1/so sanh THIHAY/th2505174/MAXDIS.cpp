#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll tinh(const vector<ll>& a,ll x)
{
	auto i=lower_bound(a.begin(),a.end(),x);
	ll d=LLONG_MAX;
	if(i!=a.end())
		d=min(d,abs(*i-x));
	if(i!=a.begin())
		d=min(d,abs(x-*(--i)));
	return d;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	  cout.tie(0);
	freopen("MAXDIS.inp","r",stdin);
	freopen("MAXDIS.out","w",stdout);
	ll n,l,r;
	cin>>n>>l>>r;
	vector<ll> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	
	ll kq=l;
	ll Max=-1;
	ll d1=tinh(a,l);
	Max=d1;
	kq=l;
	ll d2=tinh(a,r);
	if(d2>Max)
	{
		Max=d2;
		kq=r;
	}
	else if(d2==Max)
		kq=r;
		
	for(int i=0;i<n-1;i++)
	{
		ll g=a[i]+(a[i+1]-a[i])/2;
		if (g>=l && g<=r)
		{
			ll k=g-a[i];
			if(k>Max)
			{
				Max=k;
				kq=g;
			}
			else if(k==Max)
				kq=max(kq,g);
			
		}
	}
	cout<<kq;
	return 0;
}
