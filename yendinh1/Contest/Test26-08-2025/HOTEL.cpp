/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "HOTEL"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<int> a(n+1), c(n+1);
    vector<pair<int,int>> p(n+1);
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se >> a[i];
    for(int i = 1; i <= n; i++)
    {
        c[i] = a[i];
        for(int j = 1; j < i; j++)
        {
            if(p[i].fi >= p[j].se)
                c[i] = max(c[i], c[j] + a[i]);
        }
    }
    cout << *max_element(c.begin() + 1, c.begin() + n + 1);
    return 0;
}