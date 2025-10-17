/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "SUPERNUM"
#define ll unsigned long long
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
    string w, x;
    while (cin >> w) {
        if (w == "#") break;
        if (!(cin >> x)) break;
        int n = w.size();
        ll sum = 1ull; 
        ll res = 0ull; 
        for(int i=0;i<n;i++){
            int j=x[i]-'0';
            ll k = 0ull, u = 0ull;
            if (w[i] == '?'){
                u += res * 10ull;
                if (j < 9) u += sum * (ll)(9 - j);
                k += sum;
            }else{
                int v = w[i] - '0';
                u += res;
                if (v > j) u += sum;
                else if (v == j) k += sum;
            }
            sum = k;
            res = u;
        }
        cout << res << '\n';
    }
    return 0;
}