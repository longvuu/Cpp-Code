/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkbina3"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int x[100], n, dem = 0;
void demql(int i, int cnt)
{
    for (ll v = 0; v <= 1; v++)
    {
        x[i] = v;
        if (i > 1 && x[i-1] == 1 && x[i] == 1) continue;
        if (i == n)
        {
            dem++;
        }
        else
            demql(i + 1, cnt);
    }
}
void inkq()
{
    for (ll i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

void quaylui(int i, int cnt)
{
    for (ll v = 0; v <= 1; v++)
    {
        x[i] = v;
        if (i > 1 && x[i-1] == 1 && x[i] == 1) continue;
        if (i == n)
        {
            inkq();
        }
        else
            quaylui(i + 1, cnt);
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
    demql(1, 0);
    cout << dem << endl;
    quaylui(1, 0);
    return 0;
}
