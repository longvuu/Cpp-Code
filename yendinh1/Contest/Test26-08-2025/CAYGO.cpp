/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAYGO"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,m;
vector<ll> a;

void sub1(){
    ll sum=0,res=LLONG_MAX;
    for(ll i =1;i<=n;i++){
        sum=0;
        for(ll j =i;j<=n;j++){
            sum+=a[j];
            if(sum>=m){
                res=min(res,j-i+1);
                break;
            }
        }
    }
    if(res!=LLONG_MAX)
        cout << res;
}
void sub23(){
    ll l=1,r=1,sum=0,res=LLONG_MAX;
    while(r<=n){
        sum+=a[r];
        while(sum>=m){
            res=min(res,r-l+1);
            sum-=a[l];
            l++;
        }
        r++;
    }
    
    if(res!=LLONG_MAX)
        cout << res;
    else 
        cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> m;
    a.resize(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    if(n<=100){
        sub1();
    }else{
        sub23();
    }
    
    return 0;
}