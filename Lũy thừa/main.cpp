#include <bits/stdc++.h>
#define ll long long
#define main firefly
using namespace std;
ll l, r, n;
int firefly()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> l >> r;
        for (ll k = 40; k >= 1; k--)
        {
            ll left = 0;
            ll right = (ll)pow(r, 1.0 / k) + 10;
            while (left < right)
            {
                ll mid = (l + r) / 2;
                ll z = 1;
                for (int i = 0; i < k; i++)
                {
                    z *= mid;
                    if (z >= l)
                    {
                        break;
                    }
                }
                if(l<=z&&z<=r){
                    cout << "Case #"<<n<<":" << " " << z;
                    break;
                }
            }
        }
    }
}