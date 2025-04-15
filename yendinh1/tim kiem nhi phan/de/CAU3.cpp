/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
ll dem(ll a,ll b, ll x){
    return x/a+x/b-x/lcm(a,b);
}
ll tknp(ll a,ll b, ll x){
    ll l = 0, r = 1e18, res=0;
    while(l <= r){
        ll m = (l+r)/2;
        if(dem(a,b,m)>=x){
            res = m;
            r = m-1;
        }
        else l = m+1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t;
    while(t--){
        ll a,b,n;
        cin >> a >> b >> n;
        cout << tknp(a,b,n) << endl;

    }
    return 0;
}