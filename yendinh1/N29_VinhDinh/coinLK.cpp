/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "coinLK"
#define ll long long
#define fi first
#define MOD 1000000007
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
    ll t;
    cin >> t;
    while(t--){
        string st;
        cin >> st;
        ll s=0,n=0;
        for(ll i =0;i<st.size();i++){
            if(st[i]=='S') s++;
            else n++;
        }
        ll t=__gcd(s,n);
        cout << s/t << "/" << n/t << '\n';
    }
    
    return 0;
}