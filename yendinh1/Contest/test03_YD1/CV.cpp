/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CV"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,k;
vector<ll> a,s;
void TRAU(){
    ll res=LLONG_MAX;
    for(ll i =0;i<=k;i++){
        ll l=0,r=0;
        for(ll j =1;j<=i;j++) l+=a[j];
        for(ll j=n-(k-i)+1;j<=n;j++){
            if(j>=i) r+=a[j];
        }
        res=min(res,max(l,r));
    }
    cout << res;
}

void FULL(){
    for(ll i =1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll res=LLONG_MAX,t=s[n];
    for(ll i=0;i<=k;i++){
        ll l =s[i];
        ll r = t-s[n-(k-i)];
        res=min(res,max(l,r));
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    a.resize(n+1);
    s.resize(n+1,0);
    for(ll i =1;i<=n;i++) cin >> a[i];
    if(n<=1e5) TRAU();
    else FULL();
    return 0;
}