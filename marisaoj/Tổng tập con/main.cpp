/*
    author: longvuu
    github: kuronight29
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    bool check = false;
    for(ll i = 0; i < (1 << n); i++){
        ll sum = 0;
        for(ll j = 0; j < n; j++){
            if(i & (1 << j)){
                sum += a[j];
            }
        }
        if(sum == k){
            check = true;
            break;
        }
    }
    if(check){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}