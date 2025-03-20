/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll solve(string st) {
    ll j = st.find('?');
    ll s = 0;
    for (ll i = 0; i < st.length(); i++){
        if (i != j) {  
            s = (s + ((i+1)%7)*(st[i]-'0')%7)%7;
        }
    }
    ll p =(j+1)%7; 
    ll k =(7-s)%7;
    ll l;
    if (j == 0){
        l = 1;
    }else{
        l = 0;
    }
    for(ll d = l; d <= 9; d++){
        if ((p * d % 7) == k){
            return d;
        }
    }
    
    return -1;  
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    cin >> st;
    ll res = solve(st);
    cout << res;
    return 0;
}