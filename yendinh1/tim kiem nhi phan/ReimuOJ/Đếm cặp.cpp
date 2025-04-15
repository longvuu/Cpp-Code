/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL ) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int  n,l,r;
    int  res=0;
    cin >> n >> l >> r;
    vector<int > a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i++) {
        int x = lower_bound(a.begin()+i+1,a.end(),l-a[i])-a.begin();
        int y = upper_bound(a.begin()+i+1,a.end(),r-a[i])-a.begin();
        if (x < y)
            res += y - x;
    }
    cout << res << '\n';
    return 0;
}