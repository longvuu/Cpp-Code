 /*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "dpbottle"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1),f(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    
    if(n == 1) {
        cout << a[1];
        return 0;
    }
    if(n == 2) {
        cout << max(a[1], a[2]);
        return 0;
    }
    
    f[0] = 0;
    f[1] = a[1];
    f[2] = max(a[1], a[2]);
    
    for(ll i = 3; i <= n; i++) {
        f[i] = max(f[i-1], a[i] + f[i-2]);
    }
    
    cout << f[n];
    return 0;
}
