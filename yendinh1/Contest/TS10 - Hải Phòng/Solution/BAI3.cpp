/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI3"
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
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int t = 0; t < q; t++) {
        int i, j;
        cin >> i >> j;
        
        int s1, s2;
        if (a[i] < a[j]) {
            s1 = a[i];
            s2 = a[j];
        } else {
            s1 = a[j];
            s2 = a[i];
        }
        bool ok = true;
        for (int k = i; k <= j; k++) {
            if (a[k] < s1 || a[k] > s2) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        int l = i, r = j;
        while (l > 1) {
            if (a[l-1] >= s1 && a[l-1] <= s2) {
                l--;
            } else {
                break;
            }
        }
        while (r < n) {
            if (a[r+1] >= s1 && a[r+1] <= s2) {
                r++;
            } else {
                break;
            }
        }
        cout << l << " " << r << "\n";
    }
    
    return 0;
}