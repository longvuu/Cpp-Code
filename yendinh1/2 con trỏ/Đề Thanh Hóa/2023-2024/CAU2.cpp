/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU2"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll n,res=0,k;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    vector<ll> a(n);
    for(ll i =0;i<n;i++){
        cin >> a[i];
        if(i > 0){
            k = i;
            while(k--){
                res+=a[k]*a[i];
            }
        }
    }
    cout << res ;
    return 0;
}