#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DOLLS.INP","r",stdin);
	freopen("DOLLS.OUT","w",stdout);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll t=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        t+=a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll m=0;
    int i=1,j=0;
    while(i<n&&j<n) 
	{
        if(i==j) 
			i++;
        else if(a[i]+k<=a[j]) 
		{
            m+=a[i];
            i++;
            j++;
        } 
		else 
            i++;
    }

    cout<<t-m;
    return 0;
}
