#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("Dolls.INP","r",stdin);
	freopen("Dolls.OUT","w",stdout);
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<int>f(n);
    for(int i=0; i<n; i++)
    {
        f[i]=a[i];
        for(int j=0; j<i; j++)
            if(a[j]+k<=a[i])
            f[i]=max(f[i],f[j]+a[i]);
    }
    cout<<*max_element(f.begin(),f.end());
}
/*
8 2
8 4 2 1 1 3 5 9
*/

