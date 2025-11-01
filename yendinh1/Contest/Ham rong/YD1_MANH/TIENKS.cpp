#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#define int long long
const int N=12000;
using namespace std;
int n;
int a[N],b[N],c[N],f[N][2];
signed main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    if (fopen("TIENKS.INP","r") != NULL) {
        freopen("TIENKS.INP","r",stdin);
        freopen("TIENKS.OUT","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(b[i]>b[j]){
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                swap(c[i],c[j]);
            }
    f[1][0]=0;
    f[1][1]=c[1];
    for(int i=2;i<=n;i++){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        int r=0;
        for(int j=i-1;j>=1;j--)
            if(b[j]<=a[i]){
                r=max(r,max(f[j][0],f[j][1]));
                break;
            }
        f[i][1]=r+c[i];
    }
    cout<<max(f[n][0],f[n][1]);
}
/*
4
1 4 5
1 3 8
3 5 4
4 6 9
*/
