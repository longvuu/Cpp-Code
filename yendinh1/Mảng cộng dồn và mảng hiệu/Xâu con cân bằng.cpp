/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool check(string st){
    ll dem=0;
    ll s=0;
    for(ll i =0;i<st.size();i++){
        if(st[i]=='1'){
            dem++;
        }else{
            s++;
        }
    }
    return s==dem;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll dem=0;
    string st;
    cin >> st;
    set<string> k;
    for(ll i =0;i<st.size();i++){
        for(ll j=0;j<st.size();j++){
            string s=st.substr(i,j);
            if(check(s)){
                k.insert(s);
            }
        }
    }
    cout << k.size();
    return 0;
}
