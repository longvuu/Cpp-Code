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
        return 0;
    }
    map<ll, ll> m, s;
    m[b] = 1;
    s[b] = b;
    for (ll x = b; x >= a;x--) {
        if (m.count(x)) {
            for (ll y = 1; y * y <= x;y++) {
                if (x % y == 0) {
                    ll d1 = y, d2 = x / y;
                    if (d1 >= a && d1 < x) {
                        if (m[d1] < m[x] + 1 || (m[d1] == m[x] + 1 && s[d1] > s[x] + d1)) {
                            m[d1] = m[x] + 1;
                            s[d1] = s[x] + d1;
                        }
                    }
                    if (d2 >= a && d2 < x && d1 != d2) {
                        if (m[d2] < m[x] + 1 || (m[d2] == m[x] + 1 && s[d2] > s[x] + d2)) {
                            m[d2] = m[x] + 1;
                            s[d2] = s[x] + d2;
                        }
                    }
                }
            }
        }
    }

    if (!m.count(a)) cout << -1;
    else cout << m[a] << ' ' << s[a];
    
    return 0;
}