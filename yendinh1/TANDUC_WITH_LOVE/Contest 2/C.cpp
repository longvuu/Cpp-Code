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
const ll MOD = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string s;
    cin >> s;
    int n =s.size(),k=0;
    for(char c:s) 
        if(c=='?')
            k++;
    vector<ll> a(n+1);
    a[0]=1;
    for(ll i =1;i<=n;i++)
        a[i]=(a[i-1]*2)%MOD;
    ll res=0,dem1=0,dem2=0;
    for(char c:s){
        if(c=='0'){
            if(k>=0)
                res=(res+dem1*a[k])%MOD;
            if(k>=1)
                res=(res+dem2*a[k-1])%MOD;
        }else if(c=='?'){
            if(k>=1)
                res=(res+dem1*a[k-1])%MOD;
            if(k>=2)
                res=(res+dem2*a[k-2])%MOD;
            dem2++;
        }else if(c=='1'){
            dem1++;
        }
    }
    cout<< (res%MOD+MOD)%MOD;
    return 0;
}