/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
int n, m;
vector<ll> a;

bool check(ll d) {
    ll last = a[0];
    int cnt = 1;
    int j = 1;
    while (j < n) {
        if (a[j] - last >= d) { cnt++; last = a[j]; }
        if (cnt >= m) return true;
        j++;
    }
    return cnt >= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    if(!(cin >> n >> m)) return 0;
    a.assign(n, 0);
    int i = 0; while (i < n) { cin >> a[i]; i++; }

    sort(a.begin(), a.end());

    if (m <= 1) { cout << 0; return 0; }

    ll lo = 0, hi = a.back() - a.front();
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;
        if (check(mid)) lo = mid; else hi = mid - 1;
    }

    cout << lo;
    return 0;
}