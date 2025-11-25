/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DAYSODEP"
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
ll dem(ll x,const vector<int> &a){
    if(x==1) return 1;
    ll res=1;
    ll t=x;
    for(int p:a){
        if(p*p>t) break;
        if(x%p==0){
            int s=0;
            while(x%p==0){ 
                x/=p; 
                s++; 
            }
            res*=(s+1);
        }
    }
    if(x>1)res*=2;
    return res;
}
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
    ll k = 0;
    for(int i=0;i<n;i++){ 
        cin >> a[i]; 
        k=max(k,a[i]); 
    }
    int N=int(sqrt(1e9)) + 1;
    vector<bool> c(N+1,false);
    vector<int> b;
    for(int i=2;i<=N;i++){
        if(!c[i]){
            b.pb(i);
            if(i*i<=N){
                for(int j=i*i;j<=N;j+=i) c[j]=true;
            }
        }
    }
    vector<ll> s(n);
    for(int i=0;i<n;i++) s[i]=dem(a[i],b);
    vector<ll> res;
    for(ll v:s){
        auto i=lower_bound(res.begin(),res.end(),v); 
        if(i==res.end()) res.pb(v);
        else *i=v;
    }
    cout << res.size();
    return 0;
}
