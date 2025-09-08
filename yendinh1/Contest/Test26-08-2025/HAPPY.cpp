/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "HAPPY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m,res;
    cin >> m >> n;
    pair<ll,ll> a[n+1];
    vector<ll> s(1E6,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    for(ll i =1;i<=n;i++){
        s[i]=s[i-1]+a[i].fi;
    }
    res=s[min(n,m)];
    for(ll i =1;i<=n;i++){
        ll t=a[i].fi+(m-1)*a[i].se;
        res=max(res,t);
        ll d=1;
        ll c=n;
        ll vt=0;
        while(d<=c){
            ll mid=(d+c)/2;
            if(mid>m){
                c=mid-1;
                continue;
            }
            if(a[mid].fi>=a[i].se){
                vt=mid;
                d=mid+1;
            }else{
                c=mid-1;
            }
            if(vt!=0){
                if(vt>=i) res=max(res,s[vt]+(m-vt)*a[i].se);
                else res=max(res,s[vt]+(m-vt-1)*a[i].se+a[i].fi);
            }
        }
    }
    cout << res;
    return 0;
}