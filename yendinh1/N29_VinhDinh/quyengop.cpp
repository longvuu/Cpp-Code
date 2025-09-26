/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "quyengop"
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
    ll n;
    cin >> n;
    ll c=sqrt(n);
    cout << (n*(n+1)/2)-(c*(c+1)*(2*c+1)/6);
    return 0;
}