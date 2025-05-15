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
const int N = 1e6 + 5;
const int LOG = 21;
int a[N];
int st[N][LOG];
int logg[N];
int n, q;

void pre() {
    logg[1] = 0;
    for (int i = 2; i < N; i++)
        logg[i] = logg[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int xuly(int l, int r) {
    int len = r - l + 1;
    int k = logg[len];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pre();
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << xuly(l, r) << '\n';
    }
    return 0;
}