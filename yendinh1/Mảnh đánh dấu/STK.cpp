/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "STK"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll n,k,l=10;
ll s[11]={0};
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    cin >> st;
    for(ll i =0;i<st.size();i++){
        k=st[i]-'0';
        s[k]++;
    }
    for(ll i =0;i<10;i++){
        if(s[i]>0){
            cout << s[i] <<i;
        }
    }
    return 0;
}
