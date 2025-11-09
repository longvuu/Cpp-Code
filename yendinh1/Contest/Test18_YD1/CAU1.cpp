/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
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
    vector<ll> a(n+1,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
    }
    ll res=0;
    for(ll i =1;i<=n;i++){
        res= a[i]*i-a[i-1]*(i-1);
        cout << res << ' ';
    }
    return 0;
}