/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkbrack"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n;
string c;
vector<string> r;
void backtrack(int o, int cl, int n, string &c, vector<string> &r)
{
    if ((int)c.size() == n)
    {
        if (o == cl)
            r.push_back(c);
        return;
    }
    if (o < n / 2)
    {
        c.push_back('(');
        backtrack(o + 1, cl, n, c, r);
        c.pop_back();
    }
    if (cl < o)
    {
        c.push_back(')');
        backtrack(o, cl + 1, n, c, r);
        c.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    if (n % 2 == 0)
        backtrack(0, 0, n, c, r);
    cout << r.size() << '\n';
    for (const string &s : r)
        cout << s << '\n';
    return 0;
}
