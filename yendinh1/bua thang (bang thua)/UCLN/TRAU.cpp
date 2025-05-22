#include <bits/stdc++.h>
#define ll long long
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
const int N = 2e5 + 5;
const int LG = 20;
using namespace std;
ll a[N];
ll st[LG][N]; 
ll lg[N];     

ll gcd(ll a, ll b) 
{
    while (b != 0) 
	{
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
void pre(ll n) 
{
    lg[1] = 0;
    for (int i = 2; i <= n; i++) 
	{
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < n; i++) 
	{
        st[0][i] = a[i];
    }
    for (int k = 1; (1 << k) <= n; k++)
	 {
        for (int i = 0; i + (1 << k) <= n; i++)
		 {
            st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int xuly(ll l, ll r) 
{
    int k = lg[r - l + 1];
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() 
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(".INP" ,"r",stdin);
	//freopen(".OUT" ,"w",stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) 
	{
        cin >> a[i];
    }

    pre(n);
    while (q--) 
	{
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << xuly(l, r) << "\n";
    }
    return 0;
}
