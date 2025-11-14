#include<bits/stdc++.h>
#define ll long long
const int Mod=1e9+7;
using namespace std;
string s;
string smax(string x,string y)
{
    if(x.size()<y.size())
        return y;
    if(x.size()>y.size())
        return x;
    int n=x.size();
    for(int i=0;i<n;i++)
    {
        if(x[i]<y[i])
            return y;
        if(x[i]>y[i])
            return x;
    }
    return x;
}
string smin(string x,string y)
{
    if(x.size()>y.size())
        return y;
    if(x.size()<y.size())
        return x;
    int n=x.size();
    for(int i=0;i<n;i++)
    {
        if(x[i]>y[i])
            return y;
        if(x[i]<y[i])
            return x;
    }
    return x;
}
bool kt(string x)
{
    string y=x;
    reverse(x.begin(),x.end());
    return y==x;
}
void th1(int n)
{
    string x=s.substr(0,n/2);
    n=x.size();
    for(int i=n-1;i>=1;i--)
    {
        if(x[i]=='9')
        {
            x[i]='0';
            continue;
        }
            x[i]++;
            break;
    }
    if(x[0]=='0')
    {
        x='1'+x;
        string y=x;
        reverse(y.begin(),y.end());
        y.erase(0,1);
        cout<<x+y;
    }
    else
    {
        string y=x;
        reverse(y.begin(),y.end());
        cout<<x+y;
    }
}
void th2(int n)
{
    string x=s.substr(0,n/2),z=s.substr(n/2+1,n/2);
    string y=x;
    reverse(y.begin(),y.end());
    if(s[n/2]<'9')
        cout<<x+char((int)s[n/2]+1)+y;
    else
    {
        for(int i=n-1;i>=1;i--)
        {
            if(x[i]=='9')
        {
            x[i]='0';
            continue;
        }
            x[i]++;
            break;
        }
        if(x[0]=='0')
        {
            x='1'+x;
            string y=x;
            reverse(y.begin(),y.end());
            cout<<x+y;
        }
        else
        {
            string y=x;
            reverse(y.begin(),y.end());
            cout<<x+"0"+y;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("palind.inp","r"))
    {
        freopen("palind.inp","r",stdin);
        freopen("palind.out","w",stdout);
    }
    cin>>s;
    if(kt(s))
    {
        cout<<s;
        return 0;
    }
    if((int)s.size()%2==0)
        th1((int)s.size());
    else
        th2((int)s.size());
    return 0;
}
/*
13578642

135798642
*/
