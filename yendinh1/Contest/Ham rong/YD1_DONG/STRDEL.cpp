#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
map<string,int> mp;
ll f(string t) 
{
    if(t.empty()) 
		return 0;
    if(mp.count(t)) 
		return mp[t];
    ll kq=t.size(); 
    ll m=t.size();
    for (int i=0;i<m;i++)
        for (int j=i;j<m;j++)
		{
            string x1=t.substr(i,j-i+1);
            string x2=x1;
            reverse(x2.begin(),x2.end());
            if(x1==x2)
			{
                string nxt=t;
                nxt.erase(i,j-i+1);
                kq=min(kq,1+f(nxt));
            }
        }
    mp[t]=kq;
    return kq;
}
ll t;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	freopen("STRDEL.INP","r",stdin);
    freopen("STRDEL.OUT","w",stdout);
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<f(s)<<'\n';	
	}
	return 0;
}
