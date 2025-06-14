/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
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
    ll n;
    string st;
    cin >> n;
    cin >> st;
    vector<int> A(n+1, 0), U(n+1, 0), G(n+1, 0), C(n+1, 0);
    for (int i = 0; i < n; i++) {
        A[i+1] = A[i] + (st[i] == 'A');
        U[i+1] = U[i] + (st[i] == 'U');
        G[i+1] = G[i] + (st[i] == 'G');
        C[i+1] = C[i] + (st[i] == 'C');
    }
    ll res = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int t = r - l + 1;
            int k = (t / 2) + 1;
            int demA = A[r+1] - A[l];
            int demU = U[r+1] - U[l];
            int demG = G[r+1] - G[l];
            int demC = C[r+1] - C[l];
            int s = (demA >= k) + (demU >= k) + 
                             (demG >= k) + (demC >= k);
            
            if (s == 1) {
                res = max(res, (ll)t);
            }
        }
    }
    
    cout << res << endl;
    return 0;
}