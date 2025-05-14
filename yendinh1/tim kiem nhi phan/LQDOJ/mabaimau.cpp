/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/mabaimau
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
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    for(ll i=0; i<n; i++) cin >> a[i];
    ll k = max_element(a.begin(), a.end()) - a.begin();
    cout << k+1 << '\n';  
    return 0;
}