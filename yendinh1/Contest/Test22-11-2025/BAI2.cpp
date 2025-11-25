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
    ll i=0,j=0,res=0,t=j,kt=false;
    while(i<a.size()||j<b.size()){
        if(a[i]+b[j]<0){
            i++;
        }else if(a[i]+b[j]>=0){
            if(a[i]+b[j]<=k){
                if(kt==false){
                    t=j;
                    kt=true;
                }
                res++;
                j++;
            }else{
                i++;
                j=t;
                kt=false;
            }
        }
        if(i>a.size()||j>b.size()) break;
    }
    cout << res;
    return 0;
}
