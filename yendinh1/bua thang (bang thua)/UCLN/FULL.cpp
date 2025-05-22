/*
    @author longvuuuu
*/
#include<bits/stdc++.h>
#define ll long long
#define taskname ""
#define pb push_back
#define fi first
#define se second
const int N = 2e5 + 5;
const int LG = 20;
using namespace std;
ll n, q;
int a[N], st[LG + 1][N];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
void pre() 
{
    for (int i = 1; i <= n; ++i) 
        st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int xuly(int l, int r) 
{
    int k = __lg(r - l + 1);
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) 
	{
        cin >> a[i];
    }
    pre();;
    while(q--)
    {
    	ll l, r;
    	cin >> l >> r;
    	cout << xuly(l, r) << endl;
	}
	return 0;
}
