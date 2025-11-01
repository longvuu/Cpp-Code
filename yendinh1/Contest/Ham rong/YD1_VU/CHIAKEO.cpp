#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
const int N =1e6;
using namespace std;
ll n,m,a[N+3],b,c,d,res=LLONG_MAX;
ll f[N+4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("CHIAKEO.INP" ,"r",stdin);
	freopen("CHIAKEO.OUT" ,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		ll k=f[i];
		ll z=f[n]-f[i];
		ll s=abs(k-z);
		res=min(res,s);
	}
	cout<<res;
	return 0;
}
