/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/86
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(vector<ll> a,ll k,ll d) {
    ll dem = 1, t = a[0];
    for (ll i =1;i<a.size();i++){
        if (a[i]-t>=d) {
            dem++;
            t = a[i];
        }
    }
    return dem >= k;
}
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
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(),a.end());
    ll l=1,r=a[n-1]-a[0],res=0;
    while (l<=r) {
        ll mid = (l+r)/2;
        if (check(a,k,mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;

    
    return 0;
}