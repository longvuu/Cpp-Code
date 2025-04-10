/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "main"
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> s(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll t = s[i] + k;
        ll l = i + 1, r = n + 1, j = n + 1;
        while (l < r)
        {
            ll mid = (l + r) / 2;
            if (s[mid] >= t)
            {
                j = mid;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        res += (n + 1) - j;
    }
    cout << res << '\n';
    return 0;
}