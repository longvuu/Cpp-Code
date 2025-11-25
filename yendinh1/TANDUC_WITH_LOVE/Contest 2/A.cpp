/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x:a) cin >> x;
    ll res=0;
    for(ll i =0;i<=30;i++){
        ll dem=0;
        for(ll j =0;j<n;j++){
            if((a[j]>>i)&1) dem++;
        }
        res+=dem*(n-dem)*(1<<i);
    }
    cout << res;
    return 0;
}