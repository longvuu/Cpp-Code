/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btktach"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n;
string t;
int m;
vector<int> a;
vector<bool> b;
void q(int p) {
    if (p == m) {
        if ((int)a.size() == n) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
                if (i < n-1) cout << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for (int l = 1; l <= 2 && p + l <= m; l++) {
        string u = t.substr(p, l);
        if (u[0] == '0') continue;
        int v = stoi(u);
        if (v >= 1 && v <= n && !b[v]) {
            b[v] = true;
            a.push_back(v);
            q(p + l);
            a.pop_back();
            b[v] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    cin >> n >> t;
    m = t.size();
    b.assign(n+1, false);
    a.clear();
    q(0);
    return 0;
}

