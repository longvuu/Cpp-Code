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
    double a, b, c;
    cin >> a >> b >> c;

    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);

    if (a + b <= c)
        cout << "KHONGPHAITAMGIAC";
    else if (a == c)
        cout << "DEU";
    else if (abs(a * a + b * b - c * c) < 1e-6)
    {
        if (a == b)
            cout << "VUONG CAN";
        else
            cout << "VUONG";
    }
    else if (a == b || b == c)
        cout << "CAN";
    else
        cout << "THUONG";

    return 0;
}