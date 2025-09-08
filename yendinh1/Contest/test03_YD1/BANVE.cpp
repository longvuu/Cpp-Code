/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BANVE"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,m;
vector<ll> a,b;

void TRAU(){
    vector<char> c(n+1,0);
    ll res=0;
    for(ll i =1;i<=m;i++){
        ll t=-1,k=-1;
        for(ll j =1;j<=n;j++){           
            if(!c[j] && a[j]<=b[i] && a[j]>t){ 
                t=a[j];
                k=j;
            }
        }
        if(k!=-1){
            c[k]=1;
            res++;
        }
    }
    cout << res;
}

void FULL(){
    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);
    ll i=1,j=1,res=0;
    while(i<=n&&j<=m){
        if(a[i]<b[j]){
            res++;
            i++;
            j++;
        }else{
            j++;
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
    cin >> n;
    a.resize(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    cin >> m;
    b.resize(m+1);
    for(ll i=1;i<=m;i++) cin >> b[i];
    FULL();
    return 0;
}