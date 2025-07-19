/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkcow3"
using namespace std;
const int M = 20;
int n;
int s[M];
int kq = INT_MAX;
void quaylui(int i, int t1, int t2, vector<int>& p) {
    if (i == n) {
        if (t1 == t2) {
            int bo = count(p.begin(), p.end(), 0);
            if (bo < kq) kq = bo;
        }
        return;
    }
    p[i] = 1;
    quaylui(i + 1, t1 + s[i], t2, p);
    p[i] = 2;
    quaylui(i + 1, t1, t2 + s[i], p);
    p[i] = 0;
    quaylui(i + 1, t1, t2, p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> p(n, 0);
    quaylui(0, 0, 0, p);
    cout << kq << '\n';
    return 0;
}