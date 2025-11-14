/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "EXH"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(ll i =0;i<n;i++)
        cin >> a[i].se >> a[i].fi;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll mx=a[0].se;
    ll mi=a[0].se;
    ll t=a[0].fi;
    ll res=0;
    for(ll i=1;i<n;i++){
        t+=a[i].fi;
        ll mx1=max(mx,a[i].se);
        ll mi1=min(mi,a[i].se);
        ll k=t-(mx1-mi1);
        if(res>k){
            t=t-a[i].fi;
        }
        else if(res<k){
            mi=mi1;
            mx=mx1;
            res=k;
        }
    }
    cout << res;
    return 0;
}
