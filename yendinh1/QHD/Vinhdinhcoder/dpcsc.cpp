#include <bits/stdc++.h>
#define taskname "dpcsc"
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll res = 1;
    for(ll d = 1; d <= 50; d++)
    {
        vector<ll> dp(n+1, 1);
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(a[i] - a[j] == d)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
    }
    cout << res;
    return 0;
}
