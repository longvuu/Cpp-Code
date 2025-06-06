/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define MOD 1000000007
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a,b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    ll k = 31;
    ll n = a.size();
    ll m = b.size();
    vector<ll> hash_a(n+1,0);
    vector<ll> hash_b(m+1,0);
    vector<ll> pow(n+1,1);
    for(ll i = 1; i <= n; i++) {
        pow[i] = (pow[i-1] * k) % MOD;
    }
    for(ll i = 0; i < n; i++) {
        hash_a[i+1] = (hash_a[i] * k + a[i]) % MOD;
    }
    for(ll i = 0; i < m; i++) {
        hash_b[i+1] = (hash_b[i] * k + b[i]) % MOD;
    }
    cout << endl;
    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll hash_sub_a = (hash_a[r+1] - (hash_a[l] * pow[r-l+1]) % MOD + MOD) % MOD;
        ll left_b = n-1-r;
        ll right_b = n-1-l;
        ll hash_sub_b = (hash_b[right_b+1] - (hash_b[left_b] * pow[right_b-left_b+1]) % MOD + MOD) % MOD;
        if(hash_sub_a == hash_sub_b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}