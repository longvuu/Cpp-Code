/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ull sqrtt(__int128 v){
    if(v <= 0) return 0;
    long double fv = (long double)v;
    ull x = (ull)sqrt(fv);
    while(( (__int128)(x+1) * (x+1) ) <= v) ++x;
    while(( (__int128)x * x) > v) --x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, a, b;
    cin >> n >> a >> b;
    ll res = LLONG_MAX;
    for(int i=0;i<n;i++){
        ll x,y,r; cin >> x >> y >> r;
        __int128 dx = (__int128)x - a;
        __int128 dy = (__int128)y - b;
        __int128 d2 = dx*dx + dy*dy;
        ull sd = sqrtt(d2); 
        bool ok = ( (__int128)sd * sd == d2);
        ll k = (ll)sd - r - (ok ? 1 : 0);
        res = min(res, k);
    }
    if(res < 0) res = -1; 
    cout << res;
    return 0;
}