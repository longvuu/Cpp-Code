/*
    @author longvuuuu
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#define taskname "TIENKS"
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
struct st
{
    ll l,r,c;
};
bool cmp(st &a,st& b){
    if (a.r!=b.r) return a.r < b.r;
    return a.l< b.l;
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
    vector<st> a;
    a.reserve(n);
    for(ll i =0;i<n;i++){
        ll x,y,z;
        cin >> x >> y >> z;
        a.pb({x,y,z});
    }
    sort(a.begin(),a.end(),cmp);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) b[i]=a[i].r;
    vector<ll> dp(n+1,0);
    for(ll i =1;i<=n;i++){
        ll l=a[i-1].l;
        ll c=a[i-1].c;
        ll p=upper_bound(b.begin(),b.begin()+(i-1),l) - b.begin();
        dp[i]=max(dp[i-1],dp[p]+c);
    }
    cout << dp[n];
    return 0;
}