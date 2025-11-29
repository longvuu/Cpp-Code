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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    ll i=1,j=n,res=0;
    sort(a.begin() + 1, a.begin() + n + 1);
    while(i<=j){
        if(a[i]+a[j]>k){
            j--;
        }else if(a[i]+a[j]<k){
            i++;
        }else{
                ll ci = 1, cj = 1;
                while (i + 1 <= j && a[i] == a[i + 1]) { ci++; i++; }
                while (j - 1 >= i && a[j] == a[j - 1]) { cj++; j--; }
            res++;
            j--;
            i++;
        }
    }
    cout << res;
    return 0;
}