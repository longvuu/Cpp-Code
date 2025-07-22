/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "WORD"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
vector<int> t, p;
vector<int> s;
int dequy(int i) {
    if (i == 0) return 0;
    if (i == 1) return t[1];
    if (s[i] != INT_MAX) return s[i];
    int s1 = dequy(i-1) + t[i];
    int s2 = dequy(i-2) + p[i-1];
    s[i] = min(s1, s2);
    return s[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n;
    cin >> n;
    t.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    p.resize(n+1);
    for(int i = 1; i < n; i++) {
        cin >> p[i];
    }
    s.resize(n+1, INT_MAX);
    cout << dequy(n) << endl;
    return 0;
}