#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,d;
    cin >> n ;
    vector<ll> a(n+1);
    vector<ll> s(n+1,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        if(s[i-1]<0){
            s[i]=a[i];
        }else{
            s[i]=s[i-1]+a[i];
        }
    }
    ll res=*max_element(s.begin(),s.end());
    cout << res;
    return 0;
}
