/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

void sub1(ll n,ll k,vector<ll> a){
    ll res=0;
    for(ll i =1;i<(1<<n);i++){
        ll t=0,dem=0;
        for(ll j =0;j<n;j++){
            if(i&(1<<j)){
                t+=a[j];
                dem++;
            }
        }
        if(t==dem*k)
            res++;
    }
    cout << res;
}


void sub2(ll n,ll k,vector<ll> a){
    unordered_map<ll,ll> dp,b;
    dp.reserve(1024); 
    b.reserve(1024);
    dp[0] = 1;
    for(ll i =0;i<n;i++){
        ll t=a[i]-k;
        b=dp; 
        for(auto &j:dp){
            b[j.fi+t]+=j.se; 
        }
        dp.swap(b);
    }
    ll res = dp[0] - 1;
    if(res < 0) res = 0;
    cout << res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll &x:a) cin >> x;
    if(n<=16){
        sub1(n,k,a);
    }else{
        sub2(n,k,a);
    }
    
    return 0;
}