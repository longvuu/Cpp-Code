/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "TIMSO2"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int N = 1e6+1;
ll n,a[N],s[N]={0},Max=0;
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[a[i]]++;
        Max=max(Max,s[a[i]]);
    }
    sort(a+1,a+n+1);
    for(ll i =1;i<=n;i++){
        if(Max==s[a[i]]){
            cout << a[i];
            break;
        }
    }
    return 0;
}
