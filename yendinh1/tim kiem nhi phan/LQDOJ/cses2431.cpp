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
    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        ll n = 1;
        ll dem = 9;  
        ll l = 1; 
        ll res = 0; 
        while (res + n * dem < k) {
            res += n * dem;
            l *= 10;
            dem *= 10;
            n++;
        }
        ll t = (k - res - 1) / n;
        ll num = l + t;
        ll x = (k - res - 1) % n;
        string s = to_string(num);
        cout << s[x] << '\n';
    }
    
    return 0;
}