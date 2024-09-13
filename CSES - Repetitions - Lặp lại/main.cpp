/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;
string st;
int main() {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    cin >> st;
    sort(st.begin(),st.end());
    ll n=st.size();
    ll res=0,s=1;
    for (ll i = 0; i < n; i++)
    {
        if(st[i]==st[i+1]){
            s++;
        }else{
            res=max(res,s);
            s=1;
        }
    }
    cout << res;
    return 0;
}