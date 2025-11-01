#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll f[30000];
ll n,m,b,c,d,res;
pair<ll,pair<ll,ll>>x[50000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("TIENKS.INP","r") != NULL) {
		freopen("TIENKS.INP" ,"r",stdin);
		freopen("TIENKS.OUT" ,"w",stdout);
	}
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i].fi>>x[i].se.fi>>x[i].se.se;
	}
	sort(x+1,x+n+1);
	for(ll i=1;i<=n;i++){
		f[i]=x[i].se.se;
		for(ll j=1;j<i;j++){
			if(x[j].se.fi<=x[i].fi){
				f[i]=max(f[i],f[j]+x[i].se.se);
			}
		}
		res=max(res,f[i]);
	}
	cout<<res;
	return 0;
}
