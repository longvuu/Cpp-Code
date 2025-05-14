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
int a[N], a2[N];
int n,q;
void pre()
{
    for (int i = 1; i < n; i++)
        a2[i] = min(a[i], a[i + 1]);
}
int xuly(int l, int r)
{
    int len = r - l + 1;
    if (len == 1)
        return a[l];
    int mn = INT_MAX;
    for (int i = l; i < r; i += 2)
        mn = min(mn, a2[i]);
    mn = min(mn, a2[r - 1]);

    return mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n;i++)
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