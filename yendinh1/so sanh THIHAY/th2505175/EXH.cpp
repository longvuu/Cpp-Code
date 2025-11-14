#include<bits/stdc++.h>
const int N=1e6;
#define ll long long
#define f first
#define se second
#define AS '\n'
using namespace std;
ll n,m,b,c,d,res;
pair<ll,ll>a[N];
void sub1()
{
    res=LLONG_MIN;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ll mx=max(a[i].f,a[j].f);
            ll mn=min(a[i].f,a[j].f);
            res=max(res,(a[i].se+a[j].se)-(mx-mn));
        }
    }
    cout<<res;
}
void sub2(){
    ll d=1,c=n;
    m=LLONG_MIN;
    while(d<=c){
        ll mx=max(a[d].f,a[c].f);
        ll mn=min(a[d].f,a[c].f);
        ll z=a[d].se+a[c].se-(mx-mn);
        if(z>=m){
            m=z;
            c--;

        }
        else d++;
    }
    cout<<m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("EXH.INP","r",stdin);
    freopen("EXH.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].f>>a[i].se;
    }
    sort(a+1,a+n+1);
    if(n<=1e4)sub1();
    else sub2();
    
    return 0;
}
