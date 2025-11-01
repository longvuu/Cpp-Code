#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#define ll long long
using namespace std;
int a[12005],b[12005],c[12005];
int v[12005];
bool cmp(int i,int j) 
{
    return b[i]<b[j];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("TIENKS.INP","r") != NULL) {
		freopen("TIENKS.INP","r",stdin);
		freopen("TIENKS.OUT","w",stdout);
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		v[i]=i;
	}
	sort(v,v+n,cmp);
	
    vector<int> dp(n);
    dp[0]=c[v[0]];
	for (int i=1;i<n;i++) 
	{
        int k=c[v[i]];
        int d=0,c=i-1,p=-1;
        while (d<=c) 
		{
            int g=(d+c)/2;
            if (b[v[g]]<=a[v[i]]) 
			{
                p=g;
                d=g+1;
            } 
			else 
                c=g-1;
        }

        if (p!=-1) 
			k+=dp[p];
        dp[i]=max(dp[i-1],k);
    }
    cout<<dp[n-1];
    return 0;
}
