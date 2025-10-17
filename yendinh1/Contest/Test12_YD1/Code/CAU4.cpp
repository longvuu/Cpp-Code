#include <bits/stdc++.h>
#define N 12
using namespace std;
int n, a[N+2][N+2], d[N+2], cc[2*N], cp[2*N], x[N+2];
int smin= (int) 1e9;
void xuly(){
    int s=0;
    for (int i=1; i<=n; i++)
        s=s+a[x[i]][i];
    smin=min(smin,s);
}
void backtrack(int k){
    for (int v=1; v<=n; v++){
        if (d[v]==0&& cc[v-k+N]==0&& cp[v+k]==0){
            x[k]=v;
            d[v]=1;
            cc[v-k+N]=1;
            cp[v+k]=1;
            if (k==n) xuly();
            else backtrack(k+1);
            d[v]=0;
            cc[v-k+N]=0;
            cp[v+k]=0;
        }
    }
}
void nhap(){
    cin>>n;
    for (int i=1; i<=n;i++)
        for (int j=1; j<=n;j++)
            cin>>a[i][j];
}
int main()
{
    freopen("CAU4.INP","r", stdin);
    freopen("CAU4.OUT", "w", stdout);
    nhap();
    backtrack(1);
    cout<<smin;
    return 0;
}
