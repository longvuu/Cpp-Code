/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n;

void quaylui(int n, int i, int j, int x)
{
    if (n == 1)
    {
         cout << i << " " << j << endl;
        return ;
    }
    quaylui(n-1,i,x,j);
    cout << i << " "<< j << endl;
    quaylui(n-1,x,j,i);
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
    cout << pow(2,n)-1 << endl;
    quaylui(n, 1, 3, 2);
    return 0;
}