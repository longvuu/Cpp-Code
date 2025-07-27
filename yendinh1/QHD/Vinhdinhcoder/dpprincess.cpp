/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpprincess"
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
    ll t;
    cin >> t;
    while(t--){
        ll res=0,n;
        cin >> n;
        vector<ll> a(n+1),f(n+1,0);
        for(ll i =1;i<=n;i++) cin >> a[i];
        f[1]=a[1];
        for(ll i =2;i<=n;i++){
            f[i]=max(f[i-1],f[i-2]+a[i]);
        }
        cout << f[n] << endl;
    }

    return 0;
}
