/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MAYMAN"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.fi < b.fi;
}
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
    vector<ll> Min(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    Min[0] = a[0];
    for(ll i = 1; i < n; i++) Min[i]=min(Min[i-1],a[i]);
    ll s1=-1,s2=-1,ans=-1;
    for(ll i = 0; i < n; i++){
       ll l = 0, r = i,res = -1;
        while(l <= r){
            ll mid = (l+r)/2;
            if(a[i]-Min[mid] >= x) res = mid, r = mid-1;
            else l = mid+1;
        }
        if(res != -1)
            if(i-res>ans)
                ans=i-res,s1=res,s2=i;
    }
    if(s1!=-1&& s2!=-1)
        cout << s1+1 << " " << s2+1;
    else 
        cout << 0;
    return 0;
}