/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DIENTICH"
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
    ll a,b,c;
    cin >> a >> b >> c;
    cout << (a*b)-((c*b)+(c*a)-(c*c)) << endl;
    return 0;
}