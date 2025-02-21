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

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    ll x,y;
    cin >> st;
    cin >> x >> y;
    ll n = st.size();
    ll l = 0, r = 0,s1 = 0, s2 = 0,res=0;
    while (r < n) {
        if (st[r] == '2') s1++;
        if (st[r] == '8') s2++;
        while (s1 > x || s2 > y) {
            if (st[l] == '2') s1--;
            if (st[l] == '8') s2--;
            l++;
        }

        res = max(res, r - l + 1);
        r++;
    }
    cout << res;
    return 0;
}