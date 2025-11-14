#include<bits/stdc++.h>
const int N=2e5;
#define ll long long
#define f first
#define se second
#define AS '\n'
using namespace std;
ll res,n,m,a,b,c,d;
void sub1()
{
    ll res=1;
    for(ll i=a;i<=b;i++){
        res=res*i/__gcd(res,i);
    }

    while(res>0){
        if(res%10==0){
            d++;
        }
        else break;
        res/=10;
    }
    cout<<d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("ZEROS.INP","r",stdin);
    freopen("ZEROS.OUT","w",stdout);
    cin>>a>>b;
   	ll d2=b/2-(a-1)/2;
    ll d5=b/5-(a-1)/5;
    ll d10=b/10-(a-1)/10;
    if(d2==0||d5==0){
    	cout<<0;
    	return 0;
	}
    d5=d5-d10;
    cout<<d5+d10;
    return 0;
}
