/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll demuoc(ll n)
{
    ll h = sqrt(n), dem = 0;
    for (ll i = 1; i <= h; i++)
    {
        if (n % i == 0)
        {
            dem += 2;
        }
    }
    if (h * h == n)
    {
        dem--;
    }
    return dem;
}
int main()
{
    // freopen(taskname ".inp", "r", stdin);
    // freopen(taskname ".out", "w", stdout);
    //  Thêm mã của bạn ở đây
    ll n,x;
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> x;
        cout << demuoc(x) << endl;
    }
    return 0;
}