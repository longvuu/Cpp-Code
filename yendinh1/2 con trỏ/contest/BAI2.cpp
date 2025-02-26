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
    vector<ll> pHoa(n + 1, 0), pThuong(n + 1, 0), pSo(n + 1, 0);
    for(ll i = 0; i < n; i++) {
        pHoa[i + 1] = pHoa[i] + hoa(s[i]);
        pThuong[i + 1] = pThuong[i] + thuong(s[i]);
        pSo[i + 1] = pSo[i] + so(s[i]);
    }
    
    ll dem = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 5; j < n; j++) {
            if(pHoa[j + 1] - pHoa[i] > 0 && 
               pThuong[j + 1] - pThuong[i] > 0 && 
               pSo[j + 1] - pSo[i] > 0) {
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}
