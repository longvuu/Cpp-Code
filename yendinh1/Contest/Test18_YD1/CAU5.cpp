/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU5"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    int n;
    cin >> n;
    ll res = LLONG_MIN;
    ll k = 0;
    for(int i = 0; i < n;i++){
        ll x;
        cin >> x;
        if(i == 0)
            k = x;
        else
            k = max(x, k + x);
        if(k > res) res = k;
    }
    cout << res;
    return 0;
}