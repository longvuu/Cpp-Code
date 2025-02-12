/*
    @author longvuuuu
    @github kuronight29
*/
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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i =0;i<n;i++){
        cin >> a[i];
    }
    ll l=0,r=a.size()-1;
    bool kt=false;
    while(l<r){
        if(a[l]+a[r]>=x){
            r--;
        }else{
            for(ll i =l;i<r;i++){
                if(a[l]+a[r]+a[i]==x){
                    cout << l << " " << i << " " << r << endl;
                    kt=true;
                    break;
                }
            }
        }
    }
    if(kt==false){
        cout << "IMPOSSIBLE";
    }
    return 0;
}
