/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAPSO"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n;
vector<ll> a;
bool kt(ll a,ll b){
    ll sum=0,sum2=0;
    while(a!=0){
        sum+=a%10;
        a/=10;
    }
    while(b!=0){
        sum2+=b%10;
        b/=10;
    }
    if(sum==sum2) return true;
    return false;
}

ll tinh(ll a){
    ll res=0;
    while(a!=0){
        res+=a%10;
        a/=10;
    }
    return res;
}

void TRAU(){
    ll dem=0;
    for(ll i =1;i<=n;i++){
        for(ll j =i+1;j<=n;j++){
            if(kt(a[i],a[j]))
                dem++;
        }
    }
    cout << dem;
}

void FULL(){
    map<ll,ll> s;
    for(ll i =1;i<=n;i++){
        s[tinh(a[i])]++;
    }
    ll res=0;
    for (auto x : s){
        ll k=x.se;
        res+= k*(k-1)/2;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    a.resize(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    if(n<=1000){
        TRAU();
    }else{
        FULL();
    }
    return 0;
}