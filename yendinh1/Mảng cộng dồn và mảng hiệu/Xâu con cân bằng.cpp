#include <bits/stdc++.h>
#define taskname ""
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
    string st;
    cin >> st;
    ll n = st.size();
    map<int, int> s;
    s[0] = 1;
    int k = 0;
    ll dem = 0;
    for (ll i = 0; i < n; i++) {
        if (st[i] == '0') {
            k--;
        } else {
            k++;
        }
        dem += s[k];
        s[k]++;
    }

    cout << dem;
    return 0;
}
