/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n,res,s,a;
int main() {
    //freopen(taskname ".inp", "r", stdin);
    //freopen(taskname ".out", "w", stdout);
    cin >> n;
    for(ll i=1;i<=n-1;i++){
        cin >> a;
        res+=a;
    }
    for(ll i=1;i<=n;i++){
        s+=i;
    }
    cout << s-res;
    return 0;
}
