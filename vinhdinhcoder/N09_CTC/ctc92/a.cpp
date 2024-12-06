/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "ctc92"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    getline(cin, st);
    while (st.size() > 0 && st[0] == ' ') st.erase(0, 1);
    while (st.size() > 0 && st.back() == ' ') st.pop_back();
    for (ll i = 1; i < st.size(); i++) {
        if (st[i] == ' ' && st[i-1] == ' ') {
            st.erase(i, 1);
            i--;
            continue;
        }
    }
    if (st.size() > 0 && st[0] >= 'a' && st[0] <= 'z') 
        st[0] -= 32;
    for (ll i = 1; i < st.size(); i++) {
        if (st[i] >= 'a' && st[i] <= 'z' && st[i-1] == ' ')
            st[i] -= 32;
        else if(st[i] >= 'A' && st[i] <= 'Z' && st[i-1] != ' ')
            st[i] += 32;
    }
    
    cout << st;
    return 0;
}