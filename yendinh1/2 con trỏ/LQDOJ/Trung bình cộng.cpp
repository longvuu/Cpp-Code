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
    int n; ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll res = a[0] + a[1] + a[2];
    ll k = x * 3LL;  
    ll d1 = abs(res - k);  
    for(int u = 2; u < n; u++) {  
        int i = 0, j = u-1;
        while(i < j) {
            ll sum = (ll)a[i] + (ll)a[j] + (ll)a[u];
            ll d = abs(sum - k);
            if(d < d1) {
                d1 = d;
                res = sum;
            } else if(d == d1 && sum > res) {
                res = sum;
            }

            if(sum < k) i++;
            else j--;
        }
    }
    cout << res;
    return 0;
}
