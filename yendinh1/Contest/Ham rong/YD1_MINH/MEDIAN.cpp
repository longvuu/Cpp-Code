#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("MEDIAN.INP","r",stdin);
	freopen("MEDIAN.OUT","w",stdout);
	ll seed,mul,add;
    int n,k;
    cin>>seed>>mul>>add>>n>>k;
    vector<ll> a(n);
    a[0]=seed;
    for (int i=1;i<n;i++)
        a[i]=(a[i-1]*mul+add)%65536;
    ll kq=0;
    int med=(k+1)/2-1;

    for (int i=0;i<=n-k;i++) 
	{
        vector<ll> b(a.begin()+i,a.begin()+i+k);
        sort(b.begin(),b.end());
        kq+=b[med];
    }
    cout<<kq;
	return 0;
}
