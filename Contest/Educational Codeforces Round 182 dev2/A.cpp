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
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }

        int outL = 0, outR = 0;
        for (int l = 1; l <= n - 2 && outL == 0; ++l) {
            for (int r = l + 1; r <= n - 1; ++r) {
                int s1 = (int)(pref[l] % 3);
                int s2 = (int)((pref[r] - pref[l]) % 3);
                int s3 = (int)((pref[n] - pref[r]) % 3);
                // Handle negative modulo
                s1 = (s1 + 3) % 3;
                s2 = (s2 + 3) % 3;
                s3 = (s3 + 3) % 3;
                bool allEqual = (s1 == s2 && s2 == s3);
                bool allDiff = (s1 != s2 && s1 != s3 && s2 != s3);
                if (allEqual || allDiff) { outL = l; outR = r; break; }
            }
        }

        cout << outL << ' ' << outR << '\n';
    }
    return 0;
}