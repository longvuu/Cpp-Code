/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DRB"
#define ll long long
#define lb long double
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
    lb s1,v1,s2,v2;
    cin >> s1 >> v1 >> s2 >> v2;
    if(v1==v2){
        if(s1==s2) cout << 0;
        else cout << -1;
        return 0;
    }
    if((s1<s2&&v1<=v2)||(s1>s2&&v1>=v2)){
        cout << -1;
        return 0;
    }
    lb t=(s2-s1)/(v1-v2);
    if(t<0)
        cout << -1;
    else
        cout << floor(t);
    return 0;
}