/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TIMSO1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int N = 1e4+1;
int n,a[N],res=0;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    map<int,int> mp;
    set<int> k;
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        mp[a[i]]++;
        res=max(res,mp[a[i]]);
        k.insert(a[i]);
    }
    for(auto i : k){
        if(mp[i]==res){
            cout << i;
            return 0;
        }
    }
    return 0;
}
