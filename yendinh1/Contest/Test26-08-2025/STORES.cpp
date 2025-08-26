/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "STORES"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool cmp(pair<ll,char> a, pair<ll,char> b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n; 
    cin >> n;
    vector<pair<ll,char>> v(n);
    for (ll i = 0; i < n; ++i) {
        ll x; char c; 
        cin >> x >> c; 
        v[i] = {x, c};
    }
    sort(v.begin(), v.end(),cmp);
    ll k = n + 5;
    vector<ll> s(2*k+1,-1);
    s[k] = 0;
    ll res = 0,t = 0;
    for(ll i = 0; i < n; i++){
        if(v[i].se == 'N') t += 1; else t -= 1;
        ll j = t + k;
        if(s[j] == -1){
            s[j] = i + 1; 
        }else{
            ll t = s[j]; 
            ll x = v[i].fi - v[t].fi; 
            if (x > res) res = x;
        }
    }
    cout << res;
    return 0;
}