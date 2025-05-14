/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "RIVBEAUT"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool check(const vector<int>& a, int L, int R) {
    int k = a[L];
    for (int i = L+1; i <= R; i++) {
        k = min(k, a[i]);
    }
    int l = -1, r = -1;
    for (int i = L; i <= R; i++) {
        if (a[i] == k) {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    for (int i = L; i < l; i++) {
        if (a[i] < a[i+1]) {
            return false;
        }
    }
    for (int i = r; i < R; i++) {
        if (a[i] > a[i+1]) {
            return false;
        }
    }
    return true;
}
bool check1(const vector<int>& a, int L, int R) {
    int k = a[L] % 2;  
    for (int i = L+1; i <= R; i++) {
        k = 1 - k;  
        if (a[i] % 2 != k) {
            return false;
        }
    }
    return true;
}
bool check2(const vector<int>& a, int L, int R) {
    return check(a, L, R) && check1(a, L, R);
}
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
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << (check2(a, L, R) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}