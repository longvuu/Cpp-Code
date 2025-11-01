/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BEAUTY"
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
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> s(n+2,0);
    vector<ll> s2(n+2,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    ll res=0;
        for(ll i =1;i<=n;i++){
            s2[i]=s2[i-1]+a[n-i+1];
        }
    for(ll i =1;i<=n/2;i++){
        if(s[i]==s2[i]) res=max(res,i);
    }
    if(res==0) cout << -1;
    else cout << res;
    return 0;
}
