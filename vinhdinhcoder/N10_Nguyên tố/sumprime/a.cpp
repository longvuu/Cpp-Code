/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "sumprime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
vector<bool> isPrime(1000001, true);
void sangnt() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= 1000000; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    sangnt(); 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll res=0;
        for(ll i =1;i<=n;i++){
            if(isPrime[i]) res+=i;
        }
        cout << res << "\n";
    }
    
    return 0;
}