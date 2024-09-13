#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    long long n,Q;
    cin>>n;
    cin>>Q;
    long long a[100009];long long x;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0; i<Q; i++)
    {

        cin>>x;
        if(binary_search(a,a+n,x))
        {
            cout<<"1"<<endl;
        }
        else
            {
                cout<<"0"<<endl;
            }
    }
        return 0;
    }