/*
    @author longvuuuu
    @problem https://marisaoj.com/problem/89
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
string xau(ll x) {
    if (x == 0) return "0";
    string res = "";
    bool check = false;
    if (x < 0) {
        check = true;
        x = -x;
    }
    while (x > 0) {
        res += char('0' + x % 10);
        x /= 10;
    }
    if (check) res += '-';
    reverse(res.begin(), res.end());
    return res;
}
// .
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll k;
    cin >> k;
    ll h = 1, t = 9, n = 1;
    while (k > h * t) {
        k -= h * t;
        h++;
        t *= 10;
        n *= 10;
    }
    ll m = n + (k - 1) / h;
    string s = xau(m);
    cout << s[(k - 1) % h];
    return 0;
}