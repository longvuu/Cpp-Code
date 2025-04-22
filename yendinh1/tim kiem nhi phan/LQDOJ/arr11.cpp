/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/arr11
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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll l = 0, r = n-1, res=0,i=-1,j=-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(a[m] <=x){
            if(a[m] == x) i = m;
            l=m+1;
        }
        else if(a[m] > x) r = m-1;
        else l = m+1;
    }
    l=0,r=n-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(a[m] >=x){
            if(a[m] == x) j = m;
            r=m-1;
        }
        else l = m+1;
    }
    if(i!= -1 && j != -1)
        res = i-j + 1;
    cout << res << "\n";
    
    return 0;
}