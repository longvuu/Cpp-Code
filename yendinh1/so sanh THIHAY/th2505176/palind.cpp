#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("palind.inp","r",stdin);
    freopen("palind.out","w",stdout);
    cin>>n;
    for(int i=n;n-i<1e8;i++){
		stringstream ss;
		ss<<i;
		string s=ss.str();
		string s1=s;
		reverse(s1.begin(),s1.end());
		if(s1==s){
			cout<<s;
			return 0;
		}
    }
    return 0;
}
