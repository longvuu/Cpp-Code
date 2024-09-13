/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define lli long long int
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    lli total = 0, m = arr[0];
    for (lli i = 1; i < n; i++)
    {
        total += max(0LL, m - arr[i]);
        m = max(m, arr[i]);
    }
    cout << total;
    return 0;
}