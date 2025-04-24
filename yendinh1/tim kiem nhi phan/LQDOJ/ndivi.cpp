/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/ndivi
*/
#include <bits/stdc++.h>
#define taskname ""
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
    ll q;
    cin >> q;
    while(q--){
        ll n,k;
        cin >> n >> k;
        ll l = 0, r = 2*k+1;
        while(l<=r){
            ll m=(l+r)/2;
            if(k<=1LL * (n-1) * m){
                r=m-1;
            } else {
                l=m+1;
            }
        }
        ll b= 1LL * n * r;
        ll a=k-1LL * (n-1) * r;
        cout << a+b << "\n";
    }
    return 0;
}