/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
const int N = 2e5 + 5;
const int LG = 20;
using namespace std;
ll n, q;
int a[N], st[LG + 1][N];
void pre() 
{
    for (int i = 1; i <= n; ++i) 
    st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int xuly(int l, int r) 
{
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    for(ll i =1;i<=n;i++) cin >> a[i];
    pre();
    while(q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        int L = l, R = r;
        while (true) {
            int s = xuly(L, R);
            if (s > t) break;
            int lo = L, hi = R, k = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (xuly(L, mid) == s) {
                    k = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (k == -1) break;
            ll res = t / a[k];
            t -= res * a[k];
            L = k + 1;
        }
        cout << t << endl;
    }
    
    return 0;
}