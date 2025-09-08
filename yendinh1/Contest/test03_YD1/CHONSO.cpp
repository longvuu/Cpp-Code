/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CHONSO"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n;
vector<ll> a;
void FULL(){
    const ll N = LLONG_MIN/4;
    ll s1=0,s2=N,s3=N;
    for(ll i =1;i<=n;i++){
        ll k1 = s1;
        if(s2>k1) k1=s2;
        if(s3>k1) k1=s3;
        ll k2 = s1 + a[i];
        ll k3;
        if(s2==N) k3=N;
        else k3=s2+a[i];
        s1=k1;
        s2=k2;
        s3=k3;
    }
    ll res=s1;
    if(s2>res) res=s2;
    if(s3>res) res=s3;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    a.resize(n+1,0);
    for(ll i =1;i<=n;i++) cin >> a[i];
    FULL();
    return 0;
}