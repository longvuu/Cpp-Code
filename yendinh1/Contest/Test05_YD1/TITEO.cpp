/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "TITEO"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
void TRAU(ll n,ll k){
    ll dem=0;
    ll x=1;
    while(true){
        if(x%n!=0){
            dem++; 
            if(dem==k){
                cout<<x<<'\n';
                break;
            }
        }
        x++;
    }
}
void FULL(ll n,ll k){
    cout <<(k+(k-1)/(n-1))<< '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll q; 
    cin >> q;
    while(q--){
        ll n,k; 
        cin >> n >> k;
        if (k<=100000) TRAU(n,k);
        else FULL(n,k);
    }
    return 0;
}