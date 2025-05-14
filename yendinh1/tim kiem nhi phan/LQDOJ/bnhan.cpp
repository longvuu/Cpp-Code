/*
    @author longvuuuu
    @problem: https://lqdoj.edu.vn/problem/bnhan
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

#include <bits/stdc++.h>
#define taskname ""
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
    ll n,m,k;
    cin >> n >> m >> k;
    ll l=1,r=n*m;
    while(l<=r){
        ll mid=(l+r)/2;
        ll dem=0;
        for (ll i = 1; i <= n; i++){
            dem+=min(mid/i,m);
        }
        if(dem<k) l=mid+1;
        else r=mid-1;
    }
    cout << l;
    return 0;
}