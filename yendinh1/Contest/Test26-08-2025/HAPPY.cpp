/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "HAPPY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool cmp(pair<ll,ll> x, pair<ll,ll> y) {
    if (x.fi != y.fi) return x.fi > y.fi;  
    return x.se < y.se;                   
}

ll tinh(vector<ll> s1,ll n) {
    ll l = 0, r = s1.size();
    while(l < r){
        // use division instead of bitwise shift
        ll mid = (l + r) / 2;
        if (s1[mid] > n) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<pair<ll,ll>> s(m);
    for (ll i = 0; i < m; ++i) s[i] = {a[i], i};
    sort(s.begin(), s.end(), cmp);
    vector<ll> s1(m), s2(m + 1, 0);
    vector<ll> pre(m); 
    for (ll i = 0; i < m; ++i) {
        s1[i] = s[i].fi;
        s2[i + 1] = s2[i] + s[i].fi;
        pre[s[i].se] = i;
    }
    ll takeFirst = min(n, m);
    ll res = s2[takeFirst];
    for (ll j = 0; j < m; ++j) {
        ll x = b[j];
        ll y = tinh(s1, x); 
        bool z = (a[j] > x);
        ll rj = pre[j];
        ll canTake;
        if (z) canTake = y - 1;
        else canTake = y;
        if (canTake < 0) canTake = 0;
        ll limit;
        if (n > 0) limit = n - 1;
        else limit = 0;        
        ll t = min(canTake, limit);              
        ll sumOthers = 0;
        if (t > 0) {
            if (z) {
                if (rj < t) sumOthers = s2[t + 1] - a[j];
                else        sumOthers = s2[t];
            } else {
                sumOthers = s2[t];
            }
        }
        ll remain = limit - t;                  
        ll total = a[j] + sumOthers + remain * x;
        if(total > res) res = total;
    }
    cout << res;
}