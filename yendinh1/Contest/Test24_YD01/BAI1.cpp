/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "BAI1"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,k;
vector<ll> d;
ll demuoc(ll n){
    ll res=0;
    for(ll i =1;i<=n;i++){
        if(n%i==0){
            res++;
        }
    }
    return res;
}
void sangdem(ll n){
    d.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        for(ll j =i;j<=n;j+=i) d[j]++;
    }
}
void sub1(){
    ll res=0;
    for(ll i =1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if(k*demuoc(i)*demuoc(j)==i*j)
                res++;
        }
    }
    cout << res;
}

void FULL(){
    unordered_map<ll, vector<ll>> s;
    for(ll i=1;i<=n;i++) s[d[i]].pb(i);
    vector<ll> ss;
    ss.reserve(s.size());
    for(auto &p:s) ss.pb(p.fi);
    sort(ss.begin(),ss.end());
    vector<ll> f(n+1,0);
    ll t=1,res=0,m=s.size();
    for(ll i=0;i<m;i++){
        ll a=ss[i];
        auto &a1=s[a];
        for(ll j=i;j<m;j++){
            ll b=ss[j];
            auto &b1=s[b];
            ll c=k*a*b;
            if(c>n*n) continue;
            t++;
            for(ll y:b1) f[y]=t;
            for(ll x:a1){
                if(c%x!=0) continue;
                ll y=c/x;
                if(y<1||y>n) continue;
                if(f[y]==t){
                    if(a==b){
                        if(x<=y) res++;
                    }else{
                        res++;
                    }
                }
            }
        }
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
    sangdem(n);
    if(n<=5000) sub1();
    else FULL();
    return 0;
}
