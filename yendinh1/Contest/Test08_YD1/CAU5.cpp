/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU5"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll N = -4000000000000000000LL;
bool check(ll t, vector<ll> &a){
    ll n = a.size();
    ll dp1[2] = {N, N};
    ll dp2[2] = {N, N};
    ll dp3 = 0;
    for(ll i = 0; i < n; i++){
        ll w;
        if (a[i] >= t)
            w = 1LL;
        else
            w = -1LL;
        ll x[2] = {N,N};
        ll y[2] = {N,N};
        ll z = N;
        for(ll p = 0; p < 2;p++){
            if (dp1[p] != N) {
                ll np = (p + 1) % 2;
                x[np] = max(x[np], dp1[p] + w);
                y[p] = max(y[p], dp1[p]);
            }
            if (dp2[p] != N) {
                ll np = (p + 1) % 2;
                x[np] = max(x[np], dp2[p] + w);
            }
        }
        if(dp3 != N){
            x[1]=max(x[1], dp3 + w);
            if(i==0) z = dp3;
        }
        dp1[0] = x[0];
        dp1[1] = x[1];
        dp2[0] = y[0];
        dp2[1] = y[1];
        dp3 = z;
    }
    if (dp1[1] >= 1 || dp2[1] >= 1) return true;
    if (dp1[0] >= 2 || dp2[0] >= 2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll l = 1;
    ll r = *max_element(a.begin(), a.end());
    ll ans = l;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid,a)){
            ans=mid;
            l=mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}