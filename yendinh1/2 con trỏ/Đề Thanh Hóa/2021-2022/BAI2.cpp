/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

bool sosanh(const string &a, const string &b)
{
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (i > 0 && a[i] == a[i - 1])
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    if (j < b.length())
    {
        return false;
    }
    while (i < a.length())
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            return false;
        }
        i++;
    }
    return true;
}

int simp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    string a, b;
    getline(cin, a);
    getline(cin, b);
    istringstream ss1(a), ss2(b);
    string s1, s2;
    int kq = 0;
    while (ss1 >> s1 && ss2 >> s2)
    {
        if (sosanh(s1, s2))
        {
            kq++;
        }
    }
    cout << kq;
    return 0;
}