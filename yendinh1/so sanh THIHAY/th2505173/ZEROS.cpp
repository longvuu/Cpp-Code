#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll a,b;
ll lcm(ll a,ll b)
{
	ll g=__gcd(a,b);
	return a/__gcd(a,b)*b;
}
ll s1(ll a,ll b,ll c)
{
	ll x=0;
	ll x1=c;
	while(c<b)
	{
		ll m=b/x1-(a-1)/x1;
		if(m>0)
		{
			x++;
			x1*=c;
		}
		else
			break;
	}
	return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("ZEROS.INP","r",stdin);
    freopen("ZEROS.OUT","w",stdout);
	cin>>a>>b;
	ll z=s1(a,b,2);
	ll y=s1(a,b,5);
	ll kq=min(y,z);
	cout<<kq;
    return 0;
}
