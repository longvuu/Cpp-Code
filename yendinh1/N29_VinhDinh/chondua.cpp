/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "chondua"
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
    
    ll n;
    cin >> n;
    map<ll, ll> a, b;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        a[x]++;
    }
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        b[x]++;
    }
    ll t = 0;
    for(auto& p : a){
        ll i = p.fi;
        ll dem = p.se;
        if(b.count(i)){
            t += dem * b[i];
        }
    }
    ll res = n * n - t;
    cout << res << endl;
    return 0;
}