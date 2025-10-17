/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CYCLIC"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

string mul(string s, int m) {
    int n = s.size();
    string res(n,'0');
    int t = 0;
    for(int i =n-1;i>=0;i--){
        int d =s[i]-'0';
        ll sum =1LL*d*m+t;
        res[i] =char('0'+(int)(sum % 10));
        t = (int)(sum / 10);
    }
    if(t) return string("#"); 
    return res;
}

bool check(string a,string b) {
    if (a.size() != b.size()) return false;
    string t = a + a;
    return t.find(b) != string::npos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    string s;
    while(cin >> s){
        int n = s.size();
        bool ok = true;
        for(int m = 1; m<=n;m++){
            string p = mul(s, m);
            if (p == "#"||!check(s,p)){ 
                ok = false; 
                break; 
            }
        }
        if(ok) 
            cout << s << " is cyclic" << '\n';
        else 
            cout << s << " is not cyclic" << '\n';
    }
    return 0;
}