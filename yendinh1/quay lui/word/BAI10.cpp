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
const int MAXN = 505;
int n, s, c[MAXN], m[MAXN];
long long res = 0;
vector<int> ss, a;
bool ok = false;
void quaylui(int i, int sum) {
    if (i > n) {
        if (sum == s) {
            res++;
            if (!ok) {
                ss = a;
                ok = true;
            }
        }
        return;
    }
    for (int k = 0; k <= m[i]; k++) {
        int t = sum + k * c[i];
        if (t > s) break;
        a[i-1] = k; 
        quaylui(i + 1, t);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    cin >> s >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> m[i];
    }
    a.assign(n, 0);
    ss.assign(n, 0);
    quaylui(1, 0);
    cout << res << '\n';
    if (res > 0) {
        for (int i = 0; i < n; i++) cout << ss[i] << " ";
        cout << '\n';
    }
    return 0;
}