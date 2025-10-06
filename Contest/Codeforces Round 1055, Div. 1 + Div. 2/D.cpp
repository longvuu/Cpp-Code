/*
    @author longvuuuu
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
    int T; cin >> T;
    while(T--) {
        int n, q; cin >> n >> q;
        vector<long long> pref(n + 1, 0);

        auto g = [](long long x){
            if(x <= 3) return 1LL;
            long long steps = 0;
            while(x > 3){
                x = x/2 + 1; // operation effect
                steps++;
            }
            return steps + 1; 
        };

        for(int i = 1; i <= n; ++i){
            long long x; cin >> x;
            pref[i] = pref[i-1] + g(x);
        }

        while(q--){
            int l,r; cin >> l >> r;
            cout << (pref[r] - pref[l-1]) << '\n';
        }
    }
    return 0;
}