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
bool cmp(ll a, ll b){
    return a>b;
}
bool idk(char c) {
    return c >= '0' && c <= '9';
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    vector<ll> s;
    getline(cin,st);
    ll k;
    cin>>k;
    vector<char> res;
    for(size_t i = 0; i < st.size(); ++i) {
        char c = st[i];
        if(idk(c)) {
            while(!res.empty() && res.back() < c && res.size() + (st.size() - i - 1) >= k) {
                res.pop_back();
            }
            if(res.size() < k) {
                res.push_back(c);
            }
        }
    }
    for (ll i = 0; i < res.size(); ++i) {
        cout << res[i];
    }
    return 0;
}