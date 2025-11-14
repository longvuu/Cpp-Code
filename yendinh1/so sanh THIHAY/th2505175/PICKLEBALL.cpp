#include<bits/stdc++.h>
const int N=2e5;
#define ll long long
#define f first
#define se second
#define AS '\n'
using namespace std;
ll n,m,a,b,c,d,res;
void sub12(){
    res=1;
    for(int i=1;i<n;i++){
        res+=i*6;
    }
    cout<<res;
}
void sub3()
{
    d=n+(n*2-2)/2-1;
    cout<<(d+n)*(d-n+1)+d+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PICKLEBALL.INP","r",stdin);
    freopen("PICKLEBALL.OUT","w",stdout);
    cin>>n;
    if(n<=1e4)sub12();
    else sub3();
    return 0;
}
