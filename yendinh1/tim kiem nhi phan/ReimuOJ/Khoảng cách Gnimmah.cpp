/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), d = n - m + 1;
    vector<int> s[26];
    for(int i = 0 ; i < n; i++){
        s[a[i] -'a'].pb(i);
    }
    ll res = 0;
    for(int i = 0; i < m; i++){
        int j = b[i] - 'a';
        res += (upper_bound(s[j].begin(), s[j].end(), i + d -1 ) - lower_bound(s[j].begin(), s[j].end() , i ));
    }
    cout << res;
    return 0;
}