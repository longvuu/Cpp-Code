#include<bits/stdc++.h>
using namespace std;

long long i,j,kq,n,x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>x;
    long long a[n+1];
    for (i=1;i<=n;i++)
        cin>>a[i];
    //nén mảng a
    kq=0;
    a[n+1]=a[n]+1;
    sort(a+1,a+1+n);
    int d=1;
    vector<int> b,c;
    for (int i=2;i<=n+1;i++)
        if (a[i]==a[i-1])
            d++;
        else
        {
            b.push_back(a[i-1]);
            c.push_back(d);
            if (a[i-1]*2==x)
                kq=kq+d*(d-1)/2;
            d=1;
        }
    //tính kết quả
    i=0; j=b.size()-1;
    while (i<j)
        if (b[i]+b[j]==x)
        {
            kq=kq+c[i]*c[j];
            i++;
            j--;
        }
        else
            if (b[i]+b[j]>x)
                j--;
            else
                i++;
    cout<<kq;
    return 0;
}
