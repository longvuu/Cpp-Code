#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <cmath>
#define ll long long
#define db double
const int M=1e9+7;
using namespace std;
int n;
ll c[12010],a[12010],b[12010],x[12010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("tienks.inp","r"))
    {
        freopen("tienks.inp","r",stdin);
        freopen("tienks.out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>x[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                swap(x[i],x[j]);
            }
            else if(a[i]==a[j])
            {
                if(b[i]>b[j])
                {
                    swap(b[i],b[j]);
                    swap(x[i],x[j]);
                }
                else if(b[i]==b[j])
                    if(x[i]>x[j])
                        swap(x[i],x[j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=x[i];
        for(int j=1;j<i;j++)
            if(a[i]>=b[j])
                c[i]=max(c[i],c[j]+x[i]);
    }
    cout<<*max_element(c+1,c+n+1);
    return 0;
}
