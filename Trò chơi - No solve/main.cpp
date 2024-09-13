/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
const int N = 1000;
bool dp[N][N];
bool kt(vector<ll> &a, ll i, ll j)
{
    if (i == 1)
        return false;
    if (dp[i][j] != -1)
        return dp[i][j];

    for (ll k = j + 1; k < i; k++)
    {
        if (a[k] >= a[j] && !kt(a, i - k + j, k))
        {
            dp[i][j] = true;
            return true;
        }
    }
    dp[i][j] = false;
    return false;
}
ll t;
int main()
{
    // freopen(taskname".inp", "r", stdin);
    // freopen(taskname".out","w",stdout);
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        memset(dp, -1, sizeof(dp)); 
        if (kt(a, n, 0))
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }
    return 0;
}