/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "LUCASA"
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
    vector<int> a = {1, 5, 6, 25, 76, 376, 625, 9376};
    int k;
    cin >> k;
    while(k--) {
        int m, n;
        cin >> m >> n;
        if (m > n) swap(m, n);
        auto l = lower_bound(a.begin(), a.end(), m);
        auto r = upper_bound(a.begin(), a.end(), n);
        cout << (r - l) << "\n";
    }
    return 0;
}