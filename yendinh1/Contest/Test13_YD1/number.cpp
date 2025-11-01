/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "NUMBER"
#define ll long long
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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    int K = (int)k;
    vector<ll> b(2*K+1, 0), c(2*K+1, 0);
    b[K] = 1;
    for(int i = 1; i <= (int)n; ++i) {
        fill(c.begin(), c.end(), 0);
        for(int j = 0; j <= 2*K; ++j) {
            if(b[j] == 0) continue;
            int d = j - K; 
            int d1 = d + (int)a[i];
            if(d1 >= 0 && d1 <= K) {
                int idx = d1 + K;
                c[idx] = (c[idx] + b[j]) % MOD;
            }
            int d2 = d - (int)a[i];
            if(d2 >= 0 && d2 <= K) {
                int idx = d2 + K;
                c[idx] = (c[idx] + b[j]) % MOD;
            }
        }
        b.swap(c);
    }
    cout << b[K] % MOD << '\n';
    return 0;
}
