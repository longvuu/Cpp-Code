#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,b,a;
int lcm(int x,int y){
	return x*y/__gcd(x,y);
}
void sub1() {
	int kq =0,dem=1;
    for(int i=a;i<=b;i++){
		dem=lcm(dem,i);
    }
    cout<<dem<<' ';
    while(dem>0){
		if(dem%10==0){
			kq++;
		}
		else break;
		dem/=10;
    }
    cout<<kq;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("zeros.inp","r",stdin);
    freopen("zeros.out","w",stdout);
    cin>>a>>b;
    sub1();
    return 0;
}
