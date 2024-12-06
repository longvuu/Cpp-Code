/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "tepuoc"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a;
    cout << "Cac uoc so cua " << n << endl;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a.push_back(i);
            if(i != n / i) {
                a.push_back(n / i);
            }
        }
    }
    sort(a.begin(), a.end());
    for(ll i : a) {
        cout << i << "\n";
    }
    return 0;
}