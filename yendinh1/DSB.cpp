/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "DSB"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll n,res=0;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> s(5,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[a[i]]++;
    }
    res+=s[4];
    if(s[2]%2==0){
        res+=s[2]/2;
    }else{
        res+=s[2]/2+1;
    }
    if(s[3]==s[1]){
        res+=s[3];
    }else{
        res+=min(s[3],s[1]);
        res+=max(s[3],s[1])-min(s[3],s[1]);
    }
    cout << res;

    return 0;
}
