/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "LIMAK"
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
    ll n,k;
    cin >> n >> k;
    ll t= 240-k;
    ll res=0,s=0;
    for(ll i =1;i<=n;i++){
        s+=5*i;
        if(s<=t)
            res++;
        else
            break;
    }
    cout << res;
    return 0;
}