/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "LKH"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,k; 
vector<ll> a; 
vector<ll> b;

void TRAU(){
    vector<ll> f(n+1,0);
    for(ll i=1;i<=n;i++){
        f[i]=f[i-1];
        ll j=i-1;
        while(j>=1&&a[i]-a[j]<k) j--;
        ll t;
        if(j >= 1)
            t = b[i] + f[j];
        else
            t = b[i];
        if(f[i]<t) f[i]=t;
    }
    cout<<f[n]<<'\n';
}

void FULL(){
    vector<ll> f(n+1,0);
    for(ll i=1;i<=n;i++){
        f[i]=f[i-1];
        ll j = upper_bound(a.begin()+1,a.begin()+i,a[i]-k) - a.begin() - 1;
        ll t = b[i] + f[j];
        if(f[i]<t) f[i]=t;
    }
    cout<<f[n]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin>>n>>k;
    a.assign(n+1,0);
    b.assign(n+1,0);
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) cin>>b[i];
    if(n<=4000) TRAU();
    else FULL();
    return 0;
}