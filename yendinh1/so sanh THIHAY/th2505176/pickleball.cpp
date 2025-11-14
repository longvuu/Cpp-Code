#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("pickleball.inp","r",stdin);
    freopen("pickleball.out","w",stdout);
    cin>>n;
    if(n<=1e4)
    {
        if(n==1)
        {
            cout<<1;
            return 0;
        }
        int dem=1;
        for(int i=1; i<n; i++)
        {
            int k=i*6;
            //cout<<k<<' ';
            dem+=k;
        }
        cout<<dem;
    }
    else
    {
       int socuoi=(n-1)*6;
		cout<<(socuoi+6)/2*(n-1)+1;
    }
    return 0;
}
