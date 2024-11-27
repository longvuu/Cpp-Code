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
string mahoa(string s, int k){
    string st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]>=65 && s[i]<=90){
            char c = ((s[i] - 65) + k) % 26 + 65;
            st +=c;
        }else if(s[i]>=97 && s[i]<=122){
            char c = ((s[i] - 97) + k) % 26 + 97;
            st +=c;
        }else{
            st+=s[i];
        }
    }
    return st;
}
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll k ;
    cin >> k;
    string s;
    cin >> s;
    cout << mahoa(s,k) << endl;
    
    return 0;
}