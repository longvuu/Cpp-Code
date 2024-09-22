/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n;
ll a, b;
ll res = 0;
int main()
{
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    cin >> n;
    vector<ll> h(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        a = abs(h[i] - h[i + 1]);
        b = abs(h[i] - h[i + 2]);
        cout << i << " " << i+1 <<  " "<<i+2 << endl;
        if (a > b)
        {
            res += b;
            if (i += 2 <= n)
            {
                i += 1;
            }
            else
            {
                i += 0;
            }
        }
        else if (a < b)
        {
            res += a;
            i += 0;
        }
        cout << res << endl;
        cout << a << " " << b << endl;
    }
    cout << res;
    return 0;
}