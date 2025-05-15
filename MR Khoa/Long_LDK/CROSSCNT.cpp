/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CROSSCNT"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int dem(int n) {
    int res = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                res++;
            else 
                res += 2;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> s(n, vector<int>(m));
    unordered_map<int, int> s1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (s1.find(a[i][j]) == s1.end()) {
                s1[a[i][j]] = dem(a[i][j]);
            }
            
            s[i][j] = s1[a[i][j]];
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = s[i][j];
            int t = min({i, j, n-i-1, m-j-1}); 
            for (int q = 1; q <= t; q++) {
                bool check = true;
                for (int k = 1; k <= q; k++) {
                    if (s[i-k][j] != k || 
                        s[i+k][j] != k || 
                        s[i][j-k] != k || 
                        s[i][j+k] != k) {
                        check = false;
                        break;
                    }
                }
                
                if (check) {
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}