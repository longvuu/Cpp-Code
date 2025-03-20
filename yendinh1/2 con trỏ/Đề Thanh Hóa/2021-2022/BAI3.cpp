/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n,0);
    for(ll &x : a) cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    ll res = 0,j=0;
    for(ll i =0;i<n;i++){
        if(b[i]==0){
            res +=a[i];
        }
        while(j<n&&a[i]-a[j]<k&&b[j]!=1){
            j++;
        }
        if(j<n){
            b[j]=1;
            j++;
        }
    }
    cout << res;
    return 0;
}
