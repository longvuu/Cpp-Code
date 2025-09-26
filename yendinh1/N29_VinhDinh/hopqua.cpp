/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "hopqua"
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
    ll n,d;
    if(!(cin >> n >> d)) return 0;
    vector<ll> a(n);
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll res=0;
    ll r=0;
    for(ll i =0;i<n;i++){
        if(r<i) r=i;
        while(r+1<n && a[r+1]-a[i]<=d) r++;
        ll k=r-i+1;
        if(k>=3){
            ll t=k-1;
            res+= t*(t-1)/2;
        }
    }
    cout << res;
    return 0;
}