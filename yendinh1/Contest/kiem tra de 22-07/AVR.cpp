/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "AVR"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll n;
    cin >> n;
    vector<ll> b(n + 1), a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> b[i];

    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        a[i] = b[i] * i - sum;
        sum += a[i];
    }

    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}