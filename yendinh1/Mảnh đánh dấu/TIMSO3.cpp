/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TIMSO3"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int Max = 0;
map<int,int> mp;
int res=1e9+1;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++) {
        mp[a[i]]++;
        Max=max(Max,mp[a[i]]);
    }
    for(int i=1;i<=n;i++){
        if(mp[a[i]]==Max&&res>a[i]){
            res=a[i];
        }
    }
    cout << res;
    return 0;
}