/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
bool check(vector<int> a, ll k, double s) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += (int)((1.0 * a[i] * a[i]) / s); 
    }
    return res >= k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n; 
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  
    double l = 0.0;
    double r = 1e10;
    double res = 0.0;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (check(a, k, mid)) {
            res = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}