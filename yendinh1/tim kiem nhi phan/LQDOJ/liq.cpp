/*
    @author longvuuuu
    @problem https://lqdoj.edu.vn/problem/liq
*/
#include <bits/stdc++.h>
#define taskname ""
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
    int a[n + 1], f[n + 1], res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    
    cout << res;
    
    return 0;
}