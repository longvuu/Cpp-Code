/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "MAXDIS"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

ll tinh(vector<ll> a,ll x){
    auto i=lower_bound(a.begin(),a.end(),x);
    ll d=LLONG_MAX;
    if(i!=a.end()){
        d=min(d,abs(x-*i));
    }
    if(i!=a.begin()){
        i--;
        d=min(d,abs(x-*i));
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll> a(n,0);
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll res=-1;
    ll x=l;
    ll k=tinh(a,l);
    res=k;
    ll k2=tinh(a,r);
    if(k2>res){
        res=k2;
        x=r;
    }else if(k2==res){
        x=r;
    }
    for(ll i =0;i<n-1;i++){
        ll mid=a[i]+(a[i+1]-a[i])/2;
        if(mid>=l&&mid<=r){
            ll k3=mid-a[i];
            if(k3>res){
                res=k3;
                x=mid;
            }
            else if(k3==res){
                x=max(x,mid);
            }
        }
    }
    cout << x;
    return 0;
}
