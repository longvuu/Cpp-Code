/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "ANCHAY"
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
    
    ll n, m;
    cin >> n >> m;
    ll res = (m/7)*2;
    ll k=n;
    for(ll i =0;i<(m%7);i++){
        if(k==7||k==8) res++;
        k++;
        if(k==9) k=2;
    }
    cout << res << endl;
    return 0;
}