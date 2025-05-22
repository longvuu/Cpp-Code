/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a,b;
    int k = 31;
    cin >> a >> b;
    int n = a.size();
    int m = b.size(); 
    // khoi tao mang hash
    vector<ll> hash_a(n+1,0);
    vector<ll> hash_b(m+1,0); 
    // khoi tao mang pow
    vector<ll> pow(n+1,1);
    for(int i = 1; i <= n; i++) {
        pow[i] = (pow[i-1] * k) % MOD;
    }
    // tinh hash cho a
    for(int i = 0; i < n; i++) {
        hash_a[i+1] = (hash_a[i] * k + a[i]) % MOD;
    }
    // tinh hash cho b
    for(int i = 0; i < m; i++) { 
        hash_b[i+1] = (hash_b[i] * k + b[i]) % MOD;
    }
    // vi tri cua xau b trong xau a
    vector<int> pos;
    for(int i = 0; i <= n - m; i++) { 
        ll hash_sub_a = (hash_a[i+m] - (hash_a[i] * pow[m]) % MOD + MOD) % MOD; 
        if(hash_sub_a == hash_b[m]) {
            pos.pb(i);
        }
    }
    // in ra hash_a va hash_b 
    for(ll i =1;i<=n;i++) cout << hash_a[i] << " ";
    cout << endl;
    for(ll i =1;i<=m;i++) cout << hash_b[i] << " ";
    cout << endl;


    // in ra vi tri
    for(int i = 0; i < pos.size(); i++) {
        cout << pos[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}