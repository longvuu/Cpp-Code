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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i =0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, r = n - 1;
    while(l<r){
        if(a[l]+a[r]==k){
            cout << "YES";
            return 0;
    }else if(a[l]+a[r]>k){
        r--;
    }else{
        l++;
    }
    }
    cout << "NO";
    return 0;
}