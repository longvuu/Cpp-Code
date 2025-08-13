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

const int N = 1001;
int n, m, F[N][N];
ll a[N], b[N];

ll sqrt3(ll x) {
    ll l = 1, r = 2154434, ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

bool prime(ll x) {
    if (x == 1) return false;
    if (x == 2) return true;
    ll t = sqrt(x);
    for (int i = 2; i < 6 && i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    for (ll k = 1; 6 * k + 1 <= t; k++) {
        if (x % (6 * k + 1) == 0 || x % (6 * k + 5) == 0) return false;
    }
    return true;
}

bool check(ll x) {
    if (x == 0) return false;
    ll t = sqrt(x);
    if (t * t == x) return true;
    t = sqrt3(x);
    return (t * t * t == x && prime(t));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string s;
    getline(cin, s);
    s = s + ' ';
    ll x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (check(x)) a[++n] = x;
            x = 0;
        } else {
            x = x * 10 + (s[i] - '0');
        }
    }
    getline(cin, s);
    s = s + ' ';
    x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (check(x)) b[++m] = x;
            x = 0;
        } else {
            x = x * 10 + (s[i] - '0');
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            F[i][j] = max(F[i-1][j], F[i][j-1]);
            if (a[i] == b[j]) {
                F[i][j] = max(F[i][j], F[i-1][j-1] + 1);
            }
        }
    }
    cout << F[n][m] << "\n";
    return 0;
}