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
ll dem(vector<int> a, ll mid,int n) {
    ll c = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= mid) {
            j++;
        }
        c +=(j-i-1); 
    }
    return c;
}
ll n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll l = 0, r = a[n-1]-a[0], res = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (dem(a, mid,n) >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
 
    cout << res;
    return 0;
}