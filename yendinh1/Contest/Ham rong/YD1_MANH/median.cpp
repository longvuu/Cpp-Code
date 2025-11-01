#include <bits/stdc++.h>
#define int long long
using namespace std;
int seed,mul,add,n,k;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("median.INP","r",stdin);
    freopen("median.OUT","w",stdout);
    cin>>seed>>mul>>add>>n>>k;
    int a[n];
    a[0]=seed;
    for(int i=1; i<n; i++)a[i]=(a[i-1]*mul+add)%65536;
    int dem=0;
    for(int i=0; i<=n-k; i++)
    {
        vector<int> b;
        for(int j=i; j<i+k; j++)
            b.push_back(a[j]);
        sort(b.begin(),b.end());
        dem+=b[(k-1)/2];
    }
    cout<<dem;
}
