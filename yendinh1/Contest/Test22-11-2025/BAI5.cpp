#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N =1e6;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI5.INP","r",stdin);
    freopen("BAI5.OUT","w",stdout);
    ll n;
    cin >> n;
    if(n==3) cout << 3;
    else if(n==4) cout << 5;
    else cout << n+2;
    return 0;
}
