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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    pair<ll,ll> b[n];
    ll dem=1;
    for(ll i =0;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(ll i =0;i<=n;i++){
        if(a[i]==a[i+1]){
            dem++;
        }else{
            b[a[i]].fi =a[i];
            b[a[i]].se = dem;
            dem=1;
        }
    }
    ll l=0,r=n-1,res=0;
        while (l < r) {
        if (a[l] + a[r] == x) {
            res+=b[a[l]].se*b[a[r]].se;
            l+=b[a[l]].se;
            r-=b[a[r]].se;
        } else if (a[l] + a[r] > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << res;
    return 0;
}
