/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tinh(ll x, ll y, ll m){
    if (y==1) return (x%m);
    ll k=tinh(x,y/2,m);
    k= (k+k)%m;
    if (y%2==1) k=(k+(x%m))%m;
    return k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a[4],m;
    cin >> a[1] >> a[2] >> a[3] >> m;
    sort(a+1,a+4);    
    if(a[2]<0) cout<<tinh(-a[1],-a[2],m);
    else cout<<tinh(a[2],a[3],m);
    return 0;
}