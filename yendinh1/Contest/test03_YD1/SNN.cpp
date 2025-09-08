/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "SNN"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ull n;

void TRAU(){
    if(n==1){
        cout << 1 << " " << 0;
        return;
    } 
    ull x=n,res=1;
    ll s=0;
    vector<pair<ull,ll>> a;
    for(ull i=2;i*i<=x;i++){
        if(x%i==0){
            ll j=0;
            while(x%i==0){
                x/=i;
                j++;
            }
            a.pb({i,j});
        }
    }
    if(x>1) a.pb({x,1});
    for(auto i:a){
        res*=i.fi;
        s=max(s,i.se);
    }
    ll t =0,p=1;
    while(p<s){ 
        p <<= 1; 
        t++; 
    }   
    bool ok=false;
    if(t>0){
        ll d=(1LL<<t);
        for(auto i:a){
            if(i.se%d!=0){
                ok=true;
                break;
            }
        }
    }
    ll u=t;
    if(ok) u=t+1;
    cout << res << " " << u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    TRAU();
    
    return 0;
}