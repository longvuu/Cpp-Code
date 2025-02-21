// https://lqdoj.edu.vn/problem/seqstr00
/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a[22];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[s.size()].pb(i); 
    }
    ll res = 0;
    for (int i = 2; i <= 20; i++) {
        for (int l = 0, r = 0; r < a[i].size(); r++) {
            while (a[i][r] - a[i][l] > m) l++;
            res += r - l;
        }
    }
    
    cout << res << endl;
    return 0;
}