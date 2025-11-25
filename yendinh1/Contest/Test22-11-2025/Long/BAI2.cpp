#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> a; // nam
    vector<ll> b; // nu
    for(ll i =1;i<=n;i++){
        ll x;
        cin >> x;
        if(x>0) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll l=0,r=-1,res=0;
    for(ll i =a.size()-1;i>=0;i--){
        while(l<b.size()&&a[i]+b[l]<0){
            l++;
        }
        if(r<l-1) r=l-1;
        while(r+1<b.size()&&a[i]+b[r+1]<=k){
            r++;
        }
        if(r>=l){
            res+=(r-l+1);
        }
    }
    cout << res;
    return 0;
}
