/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,sum=0;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> c(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        c[i] = c[i-1];
        ll k = LLONG_MAX;
        for(int j = 1; j <= 10 && j <= i; j++) 
        {
            k = min(k, a[i-j+1]);
            if (j == 10)
            {
                c[i] = max(c[i], c[i-j]+k);
            }
        }
    }
    cout << sum-c[n];
    return 0;
}