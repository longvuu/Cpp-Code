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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * a + b * b == c * c + d * d)
    {
        cout << "BANG NHAU";
    }
    else if (a * a + b * b > c * c + d * d)
    {
        cout << "B";
    }
    else
    {
        cout << "A";
    }

    return 0;
}