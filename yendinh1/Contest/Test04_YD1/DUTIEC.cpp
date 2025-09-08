/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DUTIEC"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

ll m,n;
vector<ll> a,b;

void TRAU(){
    if(n==m){
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        ll s1=0,s2=0;
        for(ll i=0;i<n;i++){
            ll d=b[i]-a[i];
            if(d>0) s1+=d;
            else s2-=d;
        }
        cout<<max(s1,s2)<<'\n';
        return;
    }
    multiset<ll> mp(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll s1=0,s2=0;
    for(ll x:b){
        auto i=mp.lower_bound(x);
        ll k;
        if(i==mp.end()){
            auto it=prev(mp.end());
            k=*it; mp.erase(it);
        }else if(i==mp.begin()){
            k=*i; mp.erase(i);
        }else{
            ll lo=*prev(i),hi=*i;
            if(llabs(hi-x)<llabs(lo-x)) k=hi;
            else k=lo;
            mp.erase(mp.find(k));
        }
        ll d=x-k;
        if(d>0) s1+=d;
        else s2-=d;
    }
    cout<<max(s1,s2)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }

    cin>>m>>n;
    a.resize(m); b.resize(n);
    for(ll i=0;i<m;i++) cin>>a[i];
    for(ll j=0;j<n;j++) cin>>b[j];
    TRAU();
    return 0;
}