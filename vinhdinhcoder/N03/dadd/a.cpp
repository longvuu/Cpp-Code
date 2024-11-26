/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll am,duong;
    am=duong=0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        if(a[i]<0){
            am++;
        }
        else{
            duong++;
        }
    }
    cout << "SO DUONG: " << duong << endl;
    cout << "SO AM: " << am << endl;
    return 0;
}
