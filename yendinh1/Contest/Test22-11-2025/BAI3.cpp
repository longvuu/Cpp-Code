#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> s(n+2,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    ll l=0,r=0,x=0;
    for(ll i =1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(s[j]-s[i-1]>=k){
                x=max(x,j-i-1);
            }
        }
    }
    if(x==0){
        cout << -1;
        return 0;
    }
    for(ll i =1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(s[j]-s[i-1]>=k){
                if(j-i-1==x){
                    cout << i << " " << j;
                    break;
                }
            }
        }
    }
    return 0;
}
