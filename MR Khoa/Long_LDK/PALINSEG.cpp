/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "PALINSEG"
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
    
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> a(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            a[i + 1][j] = a[i][j];
        }
        a[i + 1][s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int dem = 0;
        for (int i = 0; i < 26; i++) {
            int res = a[R][i] - a[L - 1][i];
            if (res % 2 == 1) {
                dem++;
            }
        }
        if (dem <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}