/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    string st;
    ll res=0;
    cin >> n;
    while(n!=0){
        res+=n%10;
        n/=10;
    }
    st=to_string(res);
    if(st[st.size()-1]=='9') cout << "YES";
    else cout << "NO";
    return 0;
}