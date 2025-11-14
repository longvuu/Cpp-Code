#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,a[1000005];
void trau()
{
     int kq,dem=LLONG_MAX;
    //sort(a+1,a+1+n,greater<int>());
    for(int j=l; j<=r; j++)
    {   int res=LLONG_MAX;
        for(int i=1; i<=n; i++)
        {
            res=min(res,abs(j-a[i]));
            if(j==a[i]){
				res=LLONG_MAX;
				break;
            }
            if(res<=dem){
				dem=res;
			    kq=i;
            }
        }
    }
    cout<<kq;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxdis.inp","r",stdin);
    freopen("maxdis.out","w",stdout);
    cin>>n>>l>>r;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    trau();
    return 0;
}
