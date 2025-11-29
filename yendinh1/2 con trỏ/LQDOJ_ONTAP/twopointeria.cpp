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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> b(m+1);
    vector<ll> c;
    for(ll i=1;i<=n;i++) cin >> a[i];
    for(ll i=1;i<=m;i++) cin >> b[i];
    ll i=1,j=1;
    while(i<=n&&j<=m){
        if(a[i]<b[j]){
            c.pb(a[i]);
            i++;
        }else if(a[i]>b[j]){
            c.pb(b[j]);
            j++;
        }else{
            c.pb(a[i]);
            c.pb(b[j]);
            j++;
            i++;
        }
    }
    while (i <= n) {
        c.pb(a[i]);
        i++;
    }
    while (j <= m) {
        c.pb(b[j]);
        j++;
    }
    for(ll x:c) cout << x << " ";
    return 0;
}