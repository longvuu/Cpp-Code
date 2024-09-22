/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n,a;
int main(){
    //freopen(taskname ".inp", "r", stdin);
    //freopen(taskname ".out", "w", stdout);
    cin >> n;
    set<ll> s;
    for(ll i =1;i<=n;i++){
        cin >> a;
        s.insert(a);
    }
    cout << s.size();
    return 0;
}