/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "timkhoa"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> k;
    vector<ll> x(k+1);
    ll res=0;
    for(ll i =1;i<=k;i++){
        cin >> x[i];
        res=__gcd(res,x[i]);
    }
    cout << res;
    return 0;
}