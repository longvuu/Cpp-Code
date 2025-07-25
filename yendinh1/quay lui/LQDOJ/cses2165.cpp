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

int n;
vector<ll> a;
ll t;
ll res = LLONG_MAX;

void quaylui(int i, ll sum1) {
    if (i == n) {
        ll sum2 = t - sum1;
         res = min(res, abs(sum1 - sum2));
        return;
    }
    quaylui(i + 1, sum1 + weights[i]);
    quaylui(i + 1, sum1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    cin >> n;
    a.resize(n);
    t = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t += t[i];
    }
    quaylui(0, 0);
    cout << res << endl;
    return 0;
}