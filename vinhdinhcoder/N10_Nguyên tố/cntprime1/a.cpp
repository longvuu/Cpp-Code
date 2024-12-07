/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "cntprime1"
#define ll long long
#define MAX 10000000 // Reduced MAX value to 10^7
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
vector<bool> prime(MAX, true);
vector<ll> s(MAX, 0);

void sangnt(ll n){
    prime[0] = prime[1] = false;
    for(ll i = 2; i * i <= n; i++){
        if(prime[i]){
            for(ll j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        s[i] = s[i - 1] + prime[i];
    }
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    sangnt(MAX);
    while(n--){
        ll a, b;
        cin >> a >> b;
        if (b >= MAX) {
            continue;
        }
        cout << s[b] - s[a - 1] << endl;
    }
    
    return 0;
}