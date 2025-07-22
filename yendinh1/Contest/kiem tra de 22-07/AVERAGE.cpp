/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "AVERAGE"
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<double> s(n + 1, 0);
    double l = -1e9, r = 1e9;
    double eps = 1e-9; 
    
    while (r - l > eps) {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i-1] + (a[i] - mid);
        }
        double minPrefix = 0;
        bool ok = false;
        for (int i = k; i <= n; i++) {
            minPrefix = min(minPrefix, s[i-k]);
            if (s[i] - minPrefix >= 0) {
                ok = true;
                break;
            }
        }
        
        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    cout << fixed << setprecision(3) << l << endl;
    
    return 0;
}