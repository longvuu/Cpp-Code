/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI1"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,k,res=0;
vector<ll> a;
void sanguoc(ll n){
    a.assign(n+1,0);
    for(ll i =1;i<=n;i++){
        for(ll j =i;j<=n;j+=i){
            a[j]++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    sanguoc(n);
    for (ll x = 1; x <= n; x++) {
        ll dx = a[x];
        for (ll dy = 1; dy <= 180; dy++) {
            if(k*dx*dy%x!=0) continue;
            ll y=(k*dx*dy)/x;
            if(y<x||y>n) continue;
            if(a[y]!=dy) continue;  
            res++;
        }
    }
    cout << res;
    return 0;
}