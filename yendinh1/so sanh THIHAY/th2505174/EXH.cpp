#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	  cout.tie(0);
	freopen("EXH.inp","r",stdin);
	freopen("EXH.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<ll,ll>> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i].se>>a[i].fi;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	ll mx=a[0].se;
	ll mi=a[0].se;
	ll t=a[0].fi;
	ll kq=0;
	for(int i=1;i<n;i++)
	{
		t+=a[i].fi;
		ll mx1=max(mx,a[i].se);
		ll mi1=min(mi,a[i].se);
		ll k=t-(mx1-mi1);
		if(kq>k)
			t=t-a[i].fi;
		else if(kq<k)
		{
			mi=mi1;
			mx=mx1;
			kq=k;
		}
	}
	cout<<kq;
	return 0;
}
