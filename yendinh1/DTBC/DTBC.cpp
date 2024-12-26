/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "DTBC"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int n,k;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".INP").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".INP").c_str(), "r", stdin);
        freopen((string(taskname) + ".OUT").c_str(), "w", stdout);
    }
    cin >> n >> k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    map<ll, int> mp;
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        ll res = 2 * k - a[i];
        if(mp[res] > 0) {
            dem += mp[res];
        }
        mp[a[i]]++;
    }
    cout << dem << endl;
    return 0;
}