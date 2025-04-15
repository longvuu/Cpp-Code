/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DAYCON"
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
    vector<ll> a(n+1), s(n+1, 0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    ll res=-1;
    ll l =1,r=n;
    while(l<=r){
        ll mid =(l+r)/2;
        bool check=true;
        for(ll i =1;i+mid-1<=n;i++){
            ll sum=s[i+mid-1]-s[i-1];
            if(sum>k){
                check = false;
                break;
            }
        }
        if(check){
            res = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << res;
    return 0;
}