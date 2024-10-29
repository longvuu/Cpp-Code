/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;
ll c,n,p;
string s;
string bai,ten;
string kq;
ll diem;
int main() {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    cin >> c>> n >> p;
    ll b=n;
    map<string,ll> m;
    map<string,ll> m1;
    while(c--){
        cin >> s;
        m[s]=0;
    }
    while(n--){
        cin >> bai >> diem;
        m1[bai]=diem;
    }
    while(p--){
        ll res=0,t;
        cin >> ten >> bai >> kq;
        if(kq =="AC"){
            m1[bai]=t;
            res = res+t;
            m[s]= res;
        }
    }
    
    return 0;
}