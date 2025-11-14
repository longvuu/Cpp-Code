#include<bits/stdc++.h>
#define ll long long
const int Mod=1e9+7;
using namespace std;
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("pickleball.inp","r"))
    {
        freopen("pickleball.inp","r",stdin);
        freopen("pickleball.out","w",stdout);
    }
    cin>>n;
    ll d=n,c=n+(n*2-2)/2-1;
    cout<<(c+d)*(c-d+1)+c+1;
    return 0;
}
/*

*/
