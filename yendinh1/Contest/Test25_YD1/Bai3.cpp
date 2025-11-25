/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll TRAU(vector<ll> a){
    ll n = a.size();
    vector<ll> s;
    for(ll i=0;i<n;i++){
        ll v = a[i];
        ll k = -1;
        for(ll j=0;j<s.size();j++){
            if(s[j] >= v){
                if(k==-1 || s[j] < s[k]) k = j;
            }
        }
        if(k==-1) s.pb(v);
        else s[k] = v;
    }
    return s.size();
}

ll FULL(vector<ll> a){
    multiset<ll> s;
    for(ll v: a){
        auto i = s.lower_bound(v);
        if(i==s.end()) s.insert(v);
        else { 
            s.erase(i); 
            s.insert(v); 
        }
    }
    return s.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    if(n <= 1000) cout << TRAU(a);
    else cout << FULL(a);
    return 0;
}
