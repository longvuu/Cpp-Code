<<<<<<< HEAD
/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll t = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        t += a[i];
    }
    
    if(t < s) {
        cout << -1;
        return 0;
    }
    
    if(n == 1) {
        cout << (a[0] >= s ? 1 : -1);
        return 0;
    }

    vector<ll> b(2*n);
    for(ll i = 0; i < n; i++) {
        b[i] = b[i+n] = a[i];
    }
    
    ll l = 0, r = 0, sum = 0;
    ll ans = 2e9;
    while(r < 2*n) {
        sum += b[r];
        while(sum >= s && l <= r) {
            ans = min(ans, r-l+1);
            sum -= b[l];
            l++;
        }
        r++;
    }
    if(ans > n) cout << -1;
    else cout << ans;
    return 0;
}
=======
/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll t = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        t += a[i];
    }

    if(t < s) {
        cout << -1;
        return 0;
    }

    if(n == 1) {
        cout << (a[0] >= s ? 1 : -1);
        return 0;
    }

    vector<ll> b(2*n);
    for(ll i = 0; i < n; i++) {
        b[i] = b[i+n] = a[i];
    }

    ll l = 0, r = 0, sum = 0;
    ll ans = 2e9;
    while(r < 2*n) {
        sum += b[r];
        while(sum >= s && l <= r) {
            ans = min(ans, r-l+1);
            sum -= b[l];
            l++;
        }
        r++;
    }
    if(ans > n) cout << -1;
    else cout << ans;
    return 0;
}
>>>>>>> bcb50e717c86b8ca78fb70150bdf9b08276fcf0b
