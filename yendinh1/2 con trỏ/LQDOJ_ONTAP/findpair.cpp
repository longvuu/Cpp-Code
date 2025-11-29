/*
    @author longvuuuu
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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n+1);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
    }
    ll i=1,j=n;
    while(i<=j){
        if(a[i]+a[j]<x){
            i++;
        }else if(a[i]+a[j]>x){
            j--;
        }else{
            cout << i << " " << j;
            return 0;
        }
    }
    cout << "No solution";
    return 0;
}