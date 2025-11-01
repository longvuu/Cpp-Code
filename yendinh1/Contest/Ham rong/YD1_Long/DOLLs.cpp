/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DOLLS"
#define ll long long
#define fi first
#define MOD 1000000007
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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i]; 
    sort(a.begin(), a.end());
    multiset<ll> b;
    for(ll i : a) {
        auto j=b.upper_bound(i-k);
        if(j==b.begin()){
            b.insert(i);
        }else{
            j--;
            b.erase(j);
            b.insert(i);
        }
    }
    ll res = 0;
    for(ll v : b) res += v;
    cout << res << '\n';
    return 0;
}