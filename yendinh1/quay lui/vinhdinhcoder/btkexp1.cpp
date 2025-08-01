/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkexp1"
#define ll long long
using namespace std;
int n;
ll m;
vector<ll> a;
vector<string> res;
void quaylui(int i, ll t, string st)
{
    if (i == n)
    {
        if (t == m) res.push_back(st);
        return;
    }
    if(a[i]<0)
    {
        quaylui(i + 1, t - a[i], st + "+" + to_string(abs(a[i])));
        quaylui(i + 1, t + a[i], st + "-" + to_string(abs(a[i])));
    }
    else if(a[i]>0)
    {
        quaylui(i + 1, t + a[i], st + "+" + to_string(abs(a[i])));
        quaylui(i + 1, t - a[i], st + "-" + to_string(abs(a[i])));
    }
    else
    {
        quaylui(i + 1, t, st + "+0");
        quaylui(i + 1, t, st + "-0");
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r"))
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    quaylui(1, a[0], to_string(a[0]));
    for (auto &s : res) cout << s << '\n';
    return 0;
}
