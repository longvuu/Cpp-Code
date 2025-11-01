#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("STRDEL.INP","r",stdin);
    freopen("STRDEL.OUT","w",stdout);
    int t;
	cin>>t;
    while(t--)
	{
        string s;
		cin>>s;
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int l=1;l<=n;l++) 
		{
            for (int i=0;i<=n-l;i++) 
			{
                int j=i+l-1;
                if (l==1) 
                    dp[i][j]=1;
                else 
				{
                    dp[i][j]=1+dp[i+1][j];
                    if (s[i]==s[j]) 
					{
                        if (l==2) 
                            dp[i][j]=1;
                        else 
                            dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                    }
                    for (int k=i+1;k<j;k++) 
					{
                        if (s[i]==s[k]) 
						{
                            int x=dp[i+1][k-1];
                            int y=dp[k][j];
                            dp[i][j]=min(dp[i][j],x+y);
                        }
                    }
                }
            }
        }
        cout<<dp[0][n-1]<<"\n";
    }
    return 0;
}
