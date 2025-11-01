#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#define ll long long
using namespace std;
ll n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("TIENKS.INP","r") != NULL) {
		freopen("TIENKS.INP","r",stdin);
		freopen("TIENKS.OUT","w",stdout);
	}
	cin>>n;
	vector<ll> a(n+1),b(n+1),c(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	vector<ll> id(n+1);
	for (int i=1;i<=n;i++) 
		id[i]=i;
	sort(id.begin()+1,id.end(),[&](ll i,ll j)
	{
		return b[i]<b[j];
	});
	vector<ll> dp(n+1),bb(n+1);
	for(int i=1;i<=n;i++)
		bb[i]=b[id[i]];
	for (int i=1;i<=n;i++) 
	{
		ll k=upper_bound(bb.begin()+1,bb.begin()+i,a[id[i]])-bb.begin()-1;
		dp[i]=max(dp[i-1],dp[k]+c[id[i]]);
	}
	cout<<dp[n];
	return 0;
}
