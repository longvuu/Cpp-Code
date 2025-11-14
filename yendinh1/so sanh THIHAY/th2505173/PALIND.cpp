#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n;
bool dx(ll x)
{
	vector<ll> cs;
	while(x>0)
	{
		ll i=x%10;
		cs.pb(i);
		x/=10;
	}
	for(int i=0;i<(ll)cs.size();i++)
		if(cs[i]!=cs[(ll)cs.size()-i-1])
		{
			return false;
			break;
		}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("PALIND.INP","r",stdin);
    freopen("PALIND.OUT","w",stdout);
	cin>>n;
//	string a=n.substr(0,(ll)n.size()/2);
//	string b=n.substr((ll)n.size()/2);
//	reverse(b.begin(),b.end());
	ll kq=n;
	while(kq>=n)
	{
		if(dx(kq))
		{
			cout<<kq;
			break;
		}
		kq++;
	}
    return 0;
}
