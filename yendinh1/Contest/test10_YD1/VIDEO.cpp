/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "VIDEO"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll l = 0;
    ll sum = 0;
    ll res = n + 1;
    for(ll r = 0; r < n; r++){
        sum += a[r];
        while(sum >= s && l <= r){
            res = min(res, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    
    if(res==n+1) {
        cout << n;
    } else {
        cout << res;
    }
    return 0;
}
