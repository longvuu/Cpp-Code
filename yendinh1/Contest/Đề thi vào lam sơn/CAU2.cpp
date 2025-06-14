/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU2"
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
    ll a, b;
    cin >> a >> b;
    if (b % a != 0) {
        cout << -1;
        return;
    }
    if (a == b) {
        cout << "1 " << a;
        return;
    }
    ll k = b / a;
    ll t = a, c = 1, m = a;
    for (ll i = 2; i * i <= k; i++) {
        while (k % i == 0) {
            m *= i;
            t += m;
            c++;
            k /= i;
        }
    }
    if (k > 1) {
        m *= k;
        t += m;
        c++;
    }
    cout << c << " " << t;
    return 0;
}