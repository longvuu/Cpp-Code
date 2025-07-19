/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btksumdiv"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
vector<ll> x,a;
ll n,k,res=0,dem=0,sum=0;

void quaylui(ll i, ll sum, ll l) {
    if (i > n) {
        if (l > 0 && sum % k == 0) res = max(res, l);
        return;
    }
    quaylui(i + 1, sum, l);
    quaylui(i + 1, sum + a[i], l + 1);
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k ;
    a.resize(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    quaylui(1, 0, 0);
    cout << res;
    
    return 0;
}