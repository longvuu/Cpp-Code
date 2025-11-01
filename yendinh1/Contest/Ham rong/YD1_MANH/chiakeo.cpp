#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],dem=LLONG_MAX;
int f[2000005];
signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("chiakeo.INP","r",stdin);
	freopen("chiakeo.OUT","w",stdout);
    cin>>n;
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        dem=min(dem,abs(f[n]-f[i]-f[i]));
    }
    cout<<dem;
}
