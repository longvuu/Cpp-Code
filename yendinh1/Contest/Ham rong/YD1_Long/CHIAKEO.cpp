/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CHIAKEO"
#define ll long long
#define fi first
#define MOD 1000000007
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
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> sum(n+2,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll res = LLONG_MAX;
    for(ll i=1;i<n;i++){
        ll x=sum[i];
        ll y=sum[n]-sum[i];
        res=min(res,abs(x-y));
    }
    cout << res;
    return 0;
}