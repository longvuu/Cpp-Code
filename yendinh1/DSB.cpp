/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "DSB"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
ll res=0;
int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> s(5,0);
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        s[a[i]]++;
    }
    res+=s[4];
    res += s[3]; 
    s[1] = max(0LL, s[1] - s[3]); 
    res += s[2] / 2; 
    if (s[2] % 2) {
        res++; 
        s[1] = max(0LL, s[1] - 2); 
    }
    res += (s[1] + 3) / 4; 
    cout << res << endl;
    return 0;
}
