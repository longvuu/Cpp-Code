/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkdaos"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
char x[100], b[100];
ll dem = 0;
string st;
void inkq()
{
    for (ll i = 0; i < st.size(); i++)
        cout << x[i];
    cout << endl;
}

void demquaylui(int i)
{
    for (ll v = 0; v < st.size(); v++)
    {
        if (b[v] == 0 && (v == 0 || st[v] != st[v-1] || b[v-1] == 1))
        {
            x[i] = st[v];
            if (i == st.size() - 1)
            {
                dem++;
            }
            else
            {
                b[v]=1;
                demquaylui(i + 1);
                b[v]=0;
            }
        }
    }
}

void quaylui(int i)
{
    for (ll v = 0; v < st.size(); v++)
    {
        if (b[v] == 0 && (v == 0 || st[v] != st[v-1] || b[v-1] == 1))
        {
            x[i] = st[v];
            if (i == st.size() - 1)
            {
                inkq();
            }
            else
            {
                b[v]=1;
                quaylui(i + 1);
                b[v]=0;
            }
        }
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
    cin >> st;
    sort(st.begin(), st.end()); 
    demquaylui(0);
    cout << dem << endl;
    quaylui(0);
    return 0;
}