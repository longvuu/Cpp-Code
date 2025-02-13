/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

bool has_seven(ll n) {
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    
    if (has_seven(n)) {
        cout << "0\n";
        return;
    }
    
    int ops = 0;
    while (!has_seven(n)) {
        ops++;
        ll add = 9;
        // Find smallest number with all 9s greater than n
        string nstr = to_string(n);
        string nines(nstr.length(), '9');
        add = stoll(nines);
        if (add <= n) add = stoll(nines + "9");
        n += add;
    }
    cout << ops << '\n';
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}