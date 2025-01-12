/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TBC"
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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    map<ll, int> mp;
    bool kt = false;
    for(int i = 1; i <= n; i++) {
        ll res = 2 * k - a[i];
        if(mp[res] > 0) {
            kt = true;
            break;
        }
        mp[a[i]]++;
    }
    if(kt == true){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}