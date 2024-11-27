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
bool cmp(pair<ll,string> a,pair<ll,string> b) {
    return a.first>b.first;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    ll dem;
    vector<pair<ll,string>> a;
    getline(cin,st);
    for(int i=0;i<st.length();i++) {
        if(st[i]!=' ') {
            string s;
            while(st[i]!=' ' && i<st.length()) {
                s+=st[i];
                i++;
            }
            a.pb({s.length(),s});
        }
    }
    sort(a.begin(),a.end(),cmp);
    cout << a[0].second;
    return 0;
}