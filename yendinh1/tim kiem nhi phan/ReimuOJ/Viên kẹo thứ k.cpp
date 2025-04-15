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
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.se<b.se;
}
int tknp(vector<pair<ll, ll>>& a, int l, int r, ll x) {
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].fi >= x) {
            r = m - 1;
            res = m;
        } else {
            l = m + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,q;
    vector<pair<int,int>>a;
    vector<pair<ll, ll>> s;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.pb({x,y});
    }
    sort(a.begin(),a.end(),cmp);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i].fi;
        s.pb({sum, a[i].se});
    }
    while(q--)
    {
        ll k;
        cin>>k;
        int i = tknp(s, 0, n - 1, k);
        if (i != -1) {
            cout << s[i].se << '\n';
        } else {
            cout << -1 << '\n'; 
        }
    }
    return 0;
}