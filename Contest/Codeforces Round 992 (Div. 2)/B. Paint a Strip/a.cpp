/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp()
{
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll t;
    cin >> t;
    while (t--)
    {
        int32_t n, res = 1, i = 1;
        cin >> n;
        while (true)
        {
            if (i >= n)
            {
                cout << res << '\n';
                break;
            }
            res++;
            i = i * 2 + 2;
        }
    }

    return 0;
}