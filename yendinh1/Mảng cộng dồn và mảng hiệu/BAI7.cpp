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
const int MAXN = 200001;
vector<ll> d(MAXN, 0); 
vector<ll> s(MAXN, 0);  
vector<ll> v(MAXN, 0);  
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }
    ll sum = 0;
    for(int i = 1; i <= 200000; i++) {
        sum += d[i];
        s[i] = sum;
        v[i] = v[i-1] + (s[i] >= k);
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l-1] << '\n';
    }
    
    return 0;
}