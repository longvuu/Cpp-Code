/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "quatangtt"
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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1,a.begin()+n+1);
    ll l =1,r=n,res=0;
    while(l<r){
        ll mid=(l+r)/2;
        if(a[l]+a[r]<=k){
            res=max(res,a[l]+a[r]);
            l++;
        }else{
            r--;
        }
    }
    cout << res;    
    return 0;
}