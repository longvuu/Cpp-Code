/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n,k,l=1,s,res=0;
int main()
{

    cin >> n;
    ll a[n+1];
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s+=a[i];
    }
    s=s/n;
    for (ll i = 1; i <= n; i++)
    {
        if(a[i]>s){
            res+=a[i];
        }
    }
    cout << res;
    return 0;
}