/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU1"
#define ll long long
using namespace std;
ll a, b;
bool check(ll x){
    ll y = sqrt(x);
    return y*y == x || (y+1)*(y+1) == x;
}
void TRAU(){
    ll dem = 0;
    for(ll i = a; i <= b; i++){
        if(check(i)) dem++;
    }
    cout << (b-a+1) - dem;
}
ll dem(ll n) {
    if (n < 1) return 0;
    ll l = 1, r = 1000000000LL;
    ll res = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid <= n / mid) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}
void FULL() {
    ll x = dem(b);
    ll y = dem(a - 1);
    cout << (b - a + 1) - (x - y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> a >> b;
    if(a <= 1e7 && b <= 1e7) {
        TRAU();
    } else {
        FULL();
    }
    return 0;
}