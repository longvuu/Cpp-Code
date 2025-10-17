#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4], M;
void nhap(){
    cin>>a[1]>>a[2]>>a[3]>>M;
}
ll nhan(ll x, ll y, ll m){
    if (y==1) return (x%m);
    ll tmp=nhan(x,y/2,m);
    tmp= (tmp+tmp)%m;
    if (y%2==1) tmp=(tmp+(x%m))%m;
    return tmp;
}
int main()
{
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    nhap();
    sort(a+1,a+4);
    if (a[2]<0)
        cout<<nhan(-a[1],-a[2],M);
    else cout<<nhan(a[2],a[3],M);
    return 0;
}
