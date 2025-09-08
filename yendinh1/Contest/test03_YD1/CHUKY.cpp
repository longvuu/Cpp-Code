/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CHUKY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
string st;

void TRAU(){
    ll n=st.size();
    for(ll i =1;i<=n;i++){
        if(n%i) continue;
        bool ok = true;
        for(ll j=i;j<n;j++){
            if(st[j]!=st[j%i]){
                ok=false;
                break;
            }
        }
        if(ok){
            cout << i;
            return;
        }
    }
    cout << n;
}

void FULL(){
    ll n = st.size();
    vector<ll> a(n,0);
    for(ll i =1;i<n;i++){
        ll j =a[i-1];
        while(j>0&&st[i]!=st[j]) j=a[i-1];
        if(st[i]==st[j]) j++;
        a[i]=j;
    }
    ll t=n-a[n-1];
    if(n%t==0){
        cout << t;
    }else{
        cout << n;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> st;
    FULL();
    return 0;
}