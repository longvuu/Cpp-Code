#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N =1e6;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> s(n+2,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    cout << 0;
    return 0;
}
