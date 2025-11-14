#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
  	freopen("EXH.INP","r",stdin);
    freopen("EXH.OUT","w",stdout);
    cin>>n;
	vector<pair<ll,ll>> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i].se>>a[i].fi;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	ll d=a[0].se;
	ll c=a[0].se;
	ll k=a[0].fi;
	ll kq=0;
	for(int i=1;i<n;i++)
	{
		k+=a[i].fi;
		ll m1=max(d,a[i].se);
		ll m2=min(c,a[i].se);
		ll x=k-m1+m2;
		if(kq>x)
			k=k-a[i].fi;
		else if(kq<x)
		{
			d=m1;
			c=m2;
			kq=x;
		}
	}
	cout<<kq;
    return 0;
}
