/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI2"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
using namespace std;
vector<int> x;
vector<string> y;
vector<int> z;
vector<string> xuly(string s){
    vector<string> r; string t;
    stringstream ss(s);
    char c;
    while(ss.get(c)){
        if(c >= '0' && c <= '9') t.push_back(c);
        else {
            if(!t.empty())
            {
                r.pb(t);
                t.clear();
            }
        }
    }
    if(!t.empty()) r.pb(t);
    return r;
}
bool cmp1(int a, int b){
    if(x[a] != x[b]) return x[a] < x[b];
    if(y[a] != y[b]) return y[a] < y[b];
    return z[a] < z[b];
}
bool cmp2(pair<ull, pair<int,string>> &a, pair<ull, pair<int,string>> &b){
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se.fi < b.se.fi;
}
void TRAU(string s){
    auto st = xuly(s);
    int m = (int)st.size();
    vector<pair<ull, pair<int,string>>> v;
    v.reserve(m);
    for(int i=0;i<m;i++){
        ull vl = 0;
        for(char c: st[i]) vl = vl*10 + (c - '0');
        v.pb({vl, {i, st[i]}});
    }
    sort(v.begin(), v.end(), cmp2);
    for(int i=0;i<m;i++){
        if(i) cout << ' ';
        cout << v[i].se.se;
    }
}
void FULL(string &s){
    auto st = xuly(s);
    int m =st.size();
    vector<string> res(m);
    x.assign(m,0);
    y.assign(m,string());
    z.assign(m,0);
    vector<int> ss(m);
    for(int i=0;i<m;i++){
        res[i] = st[i];
        int p = 0;
        while(p < res[i].size() && res[i][p] == '0') ++p;
        if(p == res[i].size())
            y[i] = "0";
        else
            y[i] = res[i].substr(p);
        x[i] = y[i].size();
        z[i] = i;
        ss[i] = i;
    }
    sort(ss.begin(), ss.end(), cmp1);
    for(int i=0;i<m;i++){
        if(i) cout << ' ';
        cout << res[ss[i]];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string s;
    cin >> s;
    if(s.size() <= 255) TRAU(s);
    else FULL(s);
    return 0;
}