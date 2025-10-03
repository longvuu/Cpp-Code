/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
#define ll long long
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
    map<string, char> mp;
    mp["0000"] = '0';
    mp["0001"] = '1';
    mp["0010"] = '2';
    mp["0011"] = '3';
    mp["0100"] = '4';
    mp["0101"] = '5';
    mp["0110"] = '6';
    mp["0111"] = '7';
    mp["1000"] = '8';
    mp["1001"] = '9';
    mp["1010"] = 'A';
    mp["1011"] = 'B';
    mp["1100"] = 'C';
    mp["1101"] = 'D';
    mp["1110"] = 'E';
    mp["1111"] = 'F';
    string st;
    cin >> st;
    string res = "";
    int cham = st.find('.');
    string s1, s2;
    if(cham != string::npos){
        s1 = st.substr(0, cham);
        s2 = st.substr(cham + 1);
    }else{
        s1 = st;
        s2 = "";
    }
    while(s1.length() % 4 != 0) {
        s1 = "0" + s1;
    }
    string hex = "";
    for(int i = 0; i < s1.length(); i += 4) {
        string s = s1.substr(i, 4);
        if(mp.find(s) != mp.end()) {
            hex += mp[s];
        }
    }
    res = hex;
    if(!s2.empty()) {
        while(s2.length() % 4 != 0) {
            s2 += "0";
        }
        string t = "";
        for(int i = 0; i < s2.length(); i += 4) {
            string s = s2.substr(i, 4);
            if(mp.find(s) != mp.end()) {
                t += mp[s];
            }
        }
        res += "." + t;
    }
    
    cout << res << endl;
    
    return 0;
}