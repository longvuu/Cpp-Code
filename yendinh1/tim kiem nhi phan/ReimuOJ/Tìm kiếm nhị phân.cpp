/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    while(q--){
        ll x;
        ll l =0,r=a.size();
        cin >> x;
        while(l<=r){
            ll mid=(l+r)/2;
            if(x==a[mid]){
                cout << mid+1 << '\n';
                break;
            }else if(x<a[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    return 0;
}