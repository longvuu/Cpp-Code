/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
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
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll res=0;
    for(ll i =0;i<n;i++){
        ll l = i+1, r = n-1,k=n;
        while(l<=r){
            ll mid =(l+r)/2;
            if(a[mid] > a[i]+x){
                k = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        res+=n-k;
    }
    cout << res;
    return 0;
}