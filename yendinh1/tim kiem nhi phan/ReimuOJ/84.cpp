/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/84
*/
#include <bits/stdc++.h>
#define taskname "84"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(ll x, ll n) {
    return x/3+x/5+x/7-x/15-x/21-x/35+x/105>=n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    ll l = 1, r=1e18,res=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid,n)){
            res=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    } 
    cout << res << endl;
    return 0;
}