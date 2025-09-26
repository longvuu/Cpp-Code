/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "chiahet"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

ll lcm(ll x,ll y,ll limit){
    ll g=__gcd(x,y);
    ll res=x/g*y;
    if(res>limit) return limit+1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    ll k,m;
    cin >> k >> m;
    vector<ll> a(m+1);
    for(ll i=1;i<=m;i++) cin >> a[i];
    ll res=0;
    for(ll j=1;j<pow(2, m);j++){
        ll l=1;
        int b=0;
        bool ok=false;
        for(ll i=0;i<m;i++) if(j>>i&1){
            b++;
            l=lcm(l,a[i+1],k);
            if(l>k){
                ok=true;
                break;
            }
        }
        if(ok) continue;
        ll t=k/l;
        if(b%2) res+=t;
        else res-=t;
    }
    cout << res;
    return 0;
}