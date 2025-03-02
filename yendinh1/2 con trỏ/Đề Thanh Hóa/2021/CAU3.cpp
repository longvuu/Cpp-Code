/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
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
    string st;
    cin >> st;
    ll n = st.size();
    vector<ll> s(n + 1, 0);
    ll sum = 0, res = 0;
    vector<ll> dem(3, 0);
    for (ll i = 1; i <= n; i++) {
        ll k = st[i - 1] - '0';
        sum += k;
        s[i] = s[i - 1] + k;
        dem[s[i] % 3]++;
    }
    for (ll i = 1; i <= n; i++) {
        res += dem[(sum + s[i - 1]) % 3];
        dem[s[i] % 3]--;
    }
    if (sum % 3 != 0) {
        res--;
    }
    cout << res << endl;
    return 0;
}
