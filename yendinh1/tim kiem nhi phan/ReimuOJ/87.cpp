/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/87
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(ll x, ll k,vector<ll> a) {
    ll res=1,sum=0;
    for(ll i =0;i<a.size();i++){
        if(a[i]>x) return false;
        if(sum+a[i]>x){
            res++;
            sum=a[i];
        } else {
            sum+=a[i];
        }
    }
    return res<=k;
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
    vector<ll> a(n);
    ll l=0,r=0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    ll res = r;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(check(mid,k,a)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}