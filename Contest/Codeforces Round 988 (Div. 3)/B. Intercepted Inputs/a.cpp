/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

int main() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        vector<ll> a(k);
        for(ll i = 0; i < k; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        bool kt = false;
        for(ll n : a) {
            if(kt) break;
            if((k-2) % n == 0) {
                ll m = (k-2) / n;
                if(binary_search(a.begin(), a.end(), m)) {
                    cout << n << " " << m << "\n";
                    kt = true;
                }
            }
        }
    }
    return 0;
}