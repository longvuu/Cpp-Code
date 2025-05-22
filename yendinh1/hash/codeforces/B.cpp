/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
int k = 31;
ll gh(string s) {
    ll h = 0;
    for (char c : s) h = (h * k + c) % MOD;
    return h;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m;
    cin >> n >> m;
    vector<ll> pow(n+1,1);
    vector<ll> b_hash(m);
    string a,b;
    cin >> a;
    ll x=n/m;
    map<ll, vector<int>> hash_a;
    for (int i = 0; i < m; i++) {
        string s = a.substr(i * x, x);
        ll h = gh(s);
        hash_a[h].pb(i);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        b_hash[i] = gh(s); 
    }
    
    vector<int> ss(m, -1);
    for (int i = 0; i < m; i++) {
        ll h = b_hash[i];
        int j = hash_a[h].back();
        hash_a[h].pop_back();
        ss[j] = i + 1;
    }
    for (int i = 0; i < m; i++) cout << ss[i] << " ";
    cout << "\n";

    return 0;
}