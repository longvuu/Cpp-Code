/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "trambom"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> h(n+1);
    for(ll i = 1; i <= n; i++) cin >> h[i];
    sort(h.begin()+1, h.begin()+n+1);
    ll res = LLONG_MAX;
    for(ll i = 1; i <= n - k + 1; i++) {
        ll t = h[i + k - 1]- h[i];
        res = min(res, t);
    }
    cout << res << endl;
    return 0;
}