/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
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
    string s;
    cin >> s;
    ll n =s.size();
    ll res=-1,sum=0;
    ll t=0;
    for(ll i =0;i<n;i++){
        sum+=(s[i]-'0')*(i+1);
        if(s[i]=='?') t=i+1;
    }
    
    return 0;
}