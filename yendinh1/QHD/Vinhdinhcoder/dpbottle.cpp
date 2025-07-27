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
    f[0]=0;
    f[1]=a[1];
    f[2]=a[1]+a[2];
    for(ll i =3;i<=n;i++)
        f[i]=max(f[i-1],max(a[i]+f[i-2],a[i]+a[i-1]+f[i-3]));
    cout << f[n];
    return 0;
}
