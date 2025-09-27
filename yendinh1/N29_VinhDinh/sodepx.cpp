/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "sodepx"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n=a.size(); 
    ll res=0;
    for(ll t=1;t<(1ll<<n);t++){
        ll k=1;
        int dem=0;
        bool ok=false;
        for(int i=0;i<n;i++){
            if(t>>i&1){
                dem++;
                if(k > m/a[i]){ 
                    ok=true;
                    break;
                }
                k*=a[i];
            }
        }
        if(ok || k==0) continue;
        ll count=m/k;
        if(dem%2==1) res+=count;
        else res-=count;
    }
    cout << res;
    return 0;
}