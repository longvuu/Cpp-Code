/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "main"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    while(q--){
        ll x;
        ll l =1,r=n;
        cin >> x;
        ll res=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[mid]<=x){
                l=mid+1;
                res=max(res,mid);
            }else{
                r=mid-1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}