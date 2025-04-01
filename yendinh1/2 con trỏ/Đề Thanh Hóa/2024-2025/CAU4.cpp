/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll m, n, k;
    cin >> m >> n >> k;
    vector<vector<ll>> a(m + 1, vector<ll>(n + 1, 0));
    for (ll p = 0; p < k; p++)
    {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        a[x][y]++;
        if (v + 1 <= n)
            a[x][v + 1]--;
        if (u + 1 <= m)
            a[u + 1][y]--;
        if (u + 1 <= m && v + 1 <= n)
            a[u + 1][v + 1]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    vector<ll> s(n + 1, 0);
    ll res = 0;
    for (ll i = 1; i <= m; i++)
    {
        ll t = 0;
        for (ll j = 1; j <= n; j++)
        {
            ll d = s[j];
            if (i == 1 || j == 1)
            {
                s[j] = 1;
            }
            else if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1])
            {
                s[j] = min({s[j], s[j - 1], t}) + 1;
            }
            else
            {
                s[j] = 1;
            }
            res = max(res, s[j]);
            t = d;
        }
    }

    cout << res << endl;
    return 0;
}