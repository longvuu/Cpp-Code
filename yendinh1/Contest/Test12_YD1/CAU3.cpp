/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
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
    pair<int,int> a[10006];
    vector<int> b;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1, greater<>());
    int L, P;
    cin>>L>>P;
    int i=1, d=0;
    while (P<L)
    {
        while (a[i].first>=L-P && i<=n)
        {
            b.push_back(a[i].se);
            i+=1;
        }
        if (b.empty()) break;
        sort(b.begin(), b.end(), greater<int>());
        P+=b[0];
        b.erase(b.begin());
        d+=1;
    }
    if (P>=L) cout<<d;
    else cout<<-1;
    return 0;
}