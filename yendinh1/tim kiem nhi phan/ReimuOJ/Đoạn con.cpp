/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "main"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tknp(vector<ll> a, ll l, ll r, ll x){
    ll k = numeric_limits<ll>::min();
    sort(a.begin()+l, a.begin()+r+1);
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(a[mid] <= x) {
            k = max(k, a[mid]);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n+1);
    vector<ll> s(n+1,0);
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    ll res = -1;
    ll k = tknp(s, 1, n, x);
    for(ll i = n; i >= 1; i--) {
        if(s[i] == k) {
            res = i;
            break;
        }
    }
    cout << k << "\n";
    cout << res << "\n";
    return 0;
}