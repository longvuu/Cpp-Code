#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	  cout.tie(0);
	freopen("PALIND.inp","r",stdin);
	freopen("PALIND.out","w",stdout);
	string a;
	cin>>a;
	ll n=a.size();
	if(n%2==0)
	{
		string s1=a.substr(0,n/2);
		string s2=s1;
		reverse(s2.begin(),s2.end());
		cout<<s1<<s2;
	}
	else if(n%2!=0)
	{
		string s1=a.substr(0,n/2+1);
		string s2=s1;
		s2.erase(n/2);
		reverse(s2.begin(),s2.end());
		cout<<s1<<s2;
	}
}
