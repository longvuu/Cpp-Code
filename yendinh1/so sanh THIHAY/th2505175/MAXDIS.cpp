#include<bits/stdc++.h>
const int N=2e5;
#define ll long long
#define f first
#define se second
#define AS '\n'
using namespace std;
ll res,n,m,a[N],b,c,d;
ll kq;
map<ll,ll>x;
ll kt(ll g)
{
    ll z=LLONG_MAX;
    for(int i=1;i<=n;i++){
        z=min(z,abs(a[i]-g));
    }
    return z;
}
void sub2(){
    ll kq=LLONG_MAX;
    while(d<=c){
        ll mid=(d+c)/2;
        if(kt(mid)<=kq&&!x[mid]){
            res=mid;
            kq=kt(mid);
            d=mid+1;
        }
        else c=mid-1;
    }
    cout<<res;
}
void sub1(){
    res=LLONG_MAX;
    for(ll i=d;i<=c;i++){
        ll v=LLONG_MAX;
        for(ll j=1;j<=n;j++){
            v=min(v,abs(i-a[j]));
            if(i==a[j]){
                v=LLONG_MAX;
                break;
            }
        }
        if(v<=res){
            res=v;
            kq=i;
        }
    }
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MAXDIS.INP","r",stdin);
    freopen("MAXDIS.OUT","w",stdout);
    cin>>n>>d>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[a[i]]=1;
    }
    sort(a+1,a+n+1);
    if(d<=1e3&&c<=1e3)sub1();
    else sub2();
    return 0;
}
