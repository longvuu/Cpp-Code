/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
using namespace std;
#define taskname "btkbrack2"
#define pb push_back
string s;
set<string> kq;
bool h(string x) {
    int d = 0;
    for (char c : x) {
        if (c == '(') d++;
        else if (c == ')') d--;
        if (d < 0) return false;
    }
    return d == 0;
}

void ql(string t, int i, string g) {
    if (i == g.size()) {
        if (h(t) && t != "") {
            kq.insert(t);
        }
        return;
    }
    ql(t, i + 1, g);
    ql(t + g[i], i + 1, g);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> s;
    ql("", 0, s);
    cout << kq.size() << endl;
    for (const string& x : kq) {
        cout << x << endl;
    }
    return 0;
}