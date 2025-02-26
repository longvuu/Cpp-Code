/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool so(char c){
    if(c>='0'&&c<='9') return true;
    return false;
}
bool thuong(char c){
    if(c>='a'&&c<='z') return true;
    return false;
}
bool hoa(char c){
    if(c>='A'&&c<='Z') return true;
    return false;
}
int simp() {
if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
    freopen((string(taskname) + ".inp").c_str(), "r", stdin);
    freopen((string(taskname) + ".out").c_str(), "w", stdout);
}    
    string s;
    cin >> s;
    ll n = s.size();
    ll dem = 0;
    
    for(ll i = 0; i < n; i++) {
        bool cs = false, ct = false, ch = false;
        for(ll j = i; j < n; j++) {
            if(hoa(s[j])) ch = true;
            if(thuong(s[j])) ct = true;
            if(so(s[j])) cs = true;
            
            if(j - i + 1 >= 6 && ch && ct && cs) {
                dem++;
            }
        }
    }
    
    cout << dem;
    return 0;
}
