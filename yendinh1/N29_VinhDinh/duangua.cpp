/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "duangua"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n,dem=0,k;
vector<ll> a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> k >> n;
    a.assign(n+1,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
    } 
    sort(a.begin()+1,a.begin()+n+1);
    ll res=0,dem=0;
    for(ll i =n;i>=1;i-=2){
        res+=a[i]*a[i-1];
        dem++;
        if(dem==k){
            cout << res;
            return 0;
        }
    }
    
    return 0;
}