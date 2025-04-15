/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAPPT"
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
    ll n,k,res=0;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i =0;i<n;i++)  cin >> a[i];
    map<ll,ll> s;
    for(ll i =0;i<n;i++){
        ll x=k-a[i];
        if(s[x]>0) res+=s[x];
        s[a[i]]++;
    }
    cout << res;
    return 0;
}