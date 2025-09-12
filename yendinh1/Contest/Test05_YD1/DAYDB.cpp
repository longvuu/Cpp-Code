/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DAYDB"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n; 
vector<ll> a; 
vector<ll> s;
void TRAU(){
    ll res=LLONG_MIN;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                res=max(res,s[j]-s[i-1]);
            }
        }
    }
    if(res==LLONG_MIN) res=0;
    cout<<res<<'\n';
}

void FULL(){
    map<ll,ll> mp; 
    ll res=LLONG_MIN;
    for(ll i=1;i<=n;i++){
        auto it=mp.find(a[i]);
        if(it!=mp.end()){
            res = max(res,s[i]-mp[a[i]]);
            mp[a[i]] = min(mp[a[i]],s[i-1]);
        }else{
            mp[a[i]]=s[i-1];
        }
    }
    if(res==LLONG_MIN) res=0;
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    cin>>n;
    a.assign(n+1,0);
    s.assign(n+1,0);
    for(ll i=1;i<=n;i++){ 
        cin>>a[i]; 
        s[i]=s[i-1]+a[i]; 
    }
    if(n<=4000) TRAU();
    else FULL();
    return 0;
}