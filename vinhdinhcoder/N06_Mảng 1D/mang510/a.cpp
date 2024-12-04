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
bool snt(ll n){
    if(n<2) return false;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll dem=0;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        if(snt(a[i])== true){
            dem++;
            cout << i+1 << " " << a[i] << endl;
        }
    }
    if(dem==0){
        cout << "KHONG CO SO NGUYEN TO";
    }
    return 0;
}