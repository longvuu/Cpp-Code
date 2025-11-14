/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "ZEROS"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll tinh(ll a,ll b,ll p){
    ll e=0;
    ll p1=p;
    while(p1<=b){
        ll cnt=(b/p1)-((a-1)/p1);
        if(cnt>0){
            e++;
            p1*=p;
        }else{
            break;
        }
    }
    return e;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a,b;
    cin >> a >> b;
    ll e2=tinh(a,b,2);
    ll e5=tinh(a,b,5);
    cout << min(e2,e5);

    return 0;
}
