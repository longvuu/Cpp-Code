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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,m;
    cin >> n >> m;
    vector<ll> hash_a(n+1);
    vector<ll> hash_b(m+1);
    vector<ll> pow(n+1,1);
    string a,b;
    cin >> a;
    for(ll i =1;i<=n;i++) pow[i]=(pow[i-1]*k)%MOD;
    for(ll i =0;i<n;i++) hash_a[i+1]=(hash_a[i]*k+a[i])%MOD;
    for(ll i =1;i<=m;i++){
        cin >> b;
        for(ll j =0;j<m;j++) hash_b[j+1]=(hash_b[j]*k+b[j])%MOD;
    }
    for(ll i =1;i<=n;i++) cout << hash_a[i] << " ";
    cout << endl;
    for(ll i =1;i<=m;i++) cout << hash_b[i] << " ";
    cout << endl;
    vector<int> pos;
    for(int i = 0; i <= n - m; i++) { 
        ll hash_sub_a = (hash_a[i+m] - (hash_a[i] * pow[m]) % MOD + MOD) % MOD; 
        if(hash_sub_a == hash_b[m]) {
            pos.pb(i);
        }
    }
    for(int i = 0; i < pos.size(); i++) {
        cout << pos[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}