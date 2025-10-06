/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "ROBOT"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main()
{
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        if (__gcd(x, y) > 1){
            cout << 0 << '\n';
            continue;
        }
        ll res = LLONG_MAX;
        for (ll p = 2; p * p <= x; p++)
        {
            if (x % p == 0)
            {
                ll k = (p - (y % p)) % p;
                res = min(res, k);
                while (x % p == 0)
                    x /= p; 
            }
        }
        if (x > 1)
        { 
            ll p = x;
            ll k = (p - (y % p)) % p;
            res = min(res, k);
        }
        cout << res << '\n';
    }
    return 0;
}