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
    for(ll i =1;i<=n;i++){
        cin >> a[i];
    }
    ll i=1;
    ll t=0;
    ll m=n+1;
    ll l=0,r=0;
    for(ll j=1;j<=n;j++){
        t+=a[j];
        while(t>=k){
            if(j-i+1<m){
                m=j-i+1;
                l=i;
                r=j;
            }
            t-=a[i];
            i++;
        }
    }
    if(m>n) cout << -1;
    else cout << l << " " << r;
    return 0;
}
