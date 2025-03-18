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

bool check(const string& a, const string& b) {
    size_t i = 0, j = 0;
    while (i < a.length()) {
        if (j >= b.length()) return false; 
        if (a[i] == b[j]) {
            i++;
            j++;
        } else if (i > 0 && a[i] == a[i-1]) {
            i++;  
        } else {
            return false;
        }
    }
    
    return j == b.length(); 
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    
    vector<string> a, b;
    stringstream ss1(line1);
    string word;
    while (ss1 >> word) {
        a.push_back(word);
    }
    
    stringstream ss2(line2);
    while (ss2 >> word) {
        b.push_back(word);
    }
    
    ll kq = 0;
    for (size_t i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i] || check(a[i], b[i])) {
            kq++;
        }
    }
    cout << kq;
    return 0;
}