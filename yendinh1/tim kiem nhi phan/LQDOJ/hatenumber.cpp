/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/hatenumber
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
<<<<<<< HEAD
    
    
=======
    ll d=1000;
    ll i=1;
    vector<ll> a;
    while(d--){
        a.pb(i);
        i++;
        while(i%3==0|| i%10==3 || i%100==3) i++;
    }
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        cout << a[n-1] << '\n';
    }
>>>>>>> 6911bfa87080f8d43d06cdd6238f702c8d99e166
    return 0;
}