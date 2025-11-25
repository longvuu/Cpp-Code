/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
vector<ll> TRAU(vector<ll> p){
    ll n =p.size()-1;
    vector<ll> d(n+1,1), pr(n+1,-1);
    ll b = 1;
    for(ll i=1;i<=n;i++){
        for(ll j=i-1;j>=1;j--){
            if(p[j] < p[i] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                pr[i] = j;
            }
        }
        if(d[i] > d[b]) b = i;
    }
    vector<ll> s;
    for(ll c = b; c != -1; c = pr[c]) s.pb(c);
    reverse(s.begin(), s.end());
    return s;
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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    vector<ll> p(n+1);
    for(ll j=1;j<=n;j++){
        p[a[j]] = j;
    }
    vector<ll> s = TRAU(p);
    cout << (ll)s.size() << '\n';
    for(ll x: s){
        cout << x << ' ' << p[x] << '\n';
    }
    return 0;
}
