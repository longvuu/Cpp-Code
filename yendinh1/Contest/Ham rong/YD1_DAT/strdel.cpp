#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int t;
string s;
bool ktdx(string x)
{
    string y=x;
    reverse(x.begin(),x.end());
    return y==x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("strdel.inp","r"))
    {
        freopen("strdel.inp","r",stdin);
        freopen("strdel.out","w",stdout);
    }
    cin>>t;
    while(t--)
    {
        cin>>s;
        int d=0;
        while(s.size()>0)
        {
            int k=1,j=0;
            for(int l=s.size();l>=2;l--)
            {
                for(int i=0;i<s.size()-l+1;i++)
                {
                    if(ktdx(s.substr(i,l)))
                    {
                        k=l;
                        j=i;
                        break;
                    }
                    if(k>1||j>0)
                        break;
                }
                if(k>1||j>0)
                    break;
            }
            s.erase(j,k);
            d++;
        }
        cout<<d<<'\n';
    }
    return 0;
}
/*

*/
