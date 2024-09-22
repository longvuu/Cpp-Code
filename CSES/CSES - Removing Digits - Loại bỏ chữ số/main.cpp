/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,dem;
string st;
string to_str(int n)
{
    string st="";
    while(n>0)
    {
        st=st+char(n%10+48);
        n/=10;
    }
    reverse(st.begin(),st.end());
    return st;
}
int to_num(string st)
{
    int n=0;
    int k=st.size();
    for(int i=0;i<k;i++)
    {
        n=n*10+(st[i]-48);
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin >> st;
    while(st.size()>0&&st[0]!='0')
    {
        char kq='0';
        n=st.size();
        for(int i=0;i<n;i++)
        {
            kq=max(kq,st[i]);
        }
        st=to_str(to_num(st)-(kq-48));
        dem++;
    }
    cout << dem;
    return 0;
}
