/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "BAI4"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int TRAU(vector<int> &a,int m){
    deque<pair<int,int>> q;
    for(int i=0;i<a.size();++i) q.emplace_back(a[i], i);
    int g = 0;
    while(!q.empty()){
        auto x = q.front(); q.pop_front();
        bool kt = false;
        for(auto &it: q) if(it.fi > x.fi){ 
            kt = true; 
            break; 
        }
        if(kt){
            q.pb(x);
            g += 1; 
        } else {
            g += 60; 
            if(x.se == m) return g;
        }
    }
    return g;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int g;
        g = TRAU(a, m);
        int p = g / 60;
        int mg = g % 60;
        cout << p << " " << mg << "\n";
    }
    return 0;
}