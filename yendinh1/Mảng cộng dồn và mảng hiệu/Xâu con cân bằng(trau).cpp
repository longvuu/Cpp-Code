#include <bits/stdc++.h>
#define taskname ""
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
    cin >> st;
    st.insert(0," ");
    int n = st.size() - 1;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        if(st[i] == '0'){
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
        } else if(st[i] == '1'){
            b[i] = b[i - 1] + 1;
            a[i] = a[i - 1];
        }
    }
    ll kq = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j++){
            if(a[j] - a[i - 1] == b[j] - b[i - 1]){
                kq++;
            }
        }
    }
    cout << kq;
    return 0;
}
