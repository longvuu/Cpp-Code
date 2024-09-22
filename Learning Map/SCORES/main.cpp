/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;
int main() {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    map<string,ll> m;
    ll n;
    cin >> n;
    while(n--){
        ll s=0;
        string y;
        ll x,z;
        cin >> x >> y;
        if(x==1){
            cin >> z;
            s=0;
            s=m[y];
            s+=z;
            m[y]=s;
        }else if(x==2){
            m[y]=0;
        }else if(x==3){
            cout << m[y]<<endl;
        }
    }
    return 0;
}