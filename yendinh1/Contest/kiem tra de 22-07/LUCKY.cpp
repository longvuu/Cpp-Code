/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "LUCKY"
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
    ll n,q;
    cin >> n;
    vector<ll> a(n+1);
    map<ll,ll> s;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        s[a[i]]++;
    } 
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << s[x] << endl;
    }
    
    return 0;
}