#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll sol(ll a,ll b,ll k)
{
	ll x=0;
	ll k1=k;
	while(k1<=b)
	{
		ll d=(b/k1)-((a-1)/k1);
		if(d>0)
		{
			x++;
			k1*=k;
		}
		else
		{
			break;
		}
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	  cout.tie(0);
	freopen("ZEROS.inp","r",stdin);
	freopen("ZEROS.out","w",stdout);
	ll a,b;
	cin>>a>>b;
	ll x2=sol(a,b,2);
	ll x5=sol(a,b,5);
	cout<<min(x2,x5);
	return 0;
}
