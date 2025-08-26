/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "GHEPDON"
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
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll> t(n+1);
    for(ll i =1;i<=n;i++) 
        cin >> t[i];
    vector<ll> a=t;
    sort(a.begin()+1,a.end());
    ll x = LLONG_MAX, j = 2;
    for(ll i =1;i<=n;i++){
        if (j<=i) j=i+1;
        while(j<=n&&a[j]-a[i]<l) j++;
        if (j<=n&&a[j]-a[i]<=r){
            x =min(x,a[j]-a[i]);
        }
    }
    if(x==LLONG_MAX){
        cout << -1;
        return 0;
    }
    vector<ll> s;            
    s.reserve(n);
    for(ll i =1;i<=n;i++){
        if(s.empty()||s.back()!= a[i]) s.pb(a[i]);
    }
    vector<vector<ll>> c(s.size()); 
    for(ll i =1;i<=n;i++){
        ll id = lower_bound(s.begin(),s.end(),t[i])-s.begin();
        c[id].pb(i); 
    }
    ll res = 0;
    for(ll i =1;i<=n;i++){
        ll u =t[i]+x;
        auto it = lower_bound(s.begin(),s.end(),u);
        if (it==s.end()||*it!=u) continue;
        ll id = it-s.begin();
        const auto k=c[id];
        auto ub = upper_bound(k.begin(),k.end(),i);
        res +=(k.end()-ub);
    }
    cout << x << ' ' << res;
    return 0;
}