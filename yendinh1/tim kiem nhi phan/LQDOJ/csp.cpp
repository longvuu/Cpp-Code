/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/csp
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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    ll res=0;
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        ll l=i+1,r=n-1,j=-1;
        while(l<=r){
            ll mid = (l+r)/2;
            if(a[mid]+a[i]<=k){
                j=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(j!=-1){
            res+=(j-i);
        }
    }
    cout << res;
    return 0;
}