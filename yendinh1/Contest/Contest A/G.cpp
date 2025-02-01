/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

bool areEqual(vector<ll>& cnt1, vector<ll>& cnt2) {
    for(ll i = 0; i < 256; i++) {
        if(cnt1[i] != cnt2[i]) return false;
    }
    return true;
}

int simp() {  
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    
    vector<ll> countA(256, 0), countWindow(256, 0);
    
    for(char c : A) {
        countA[c]++;
    }
    for(ll i = 0; i < n; i++) {
        countWindow[B[i]]++;
    }
    
    ll result = 0;
    if(areEqual(countA, countWindow)) result++;
    for(ll i = n; i < m; i++) {
        countWindow[B[i-n]]--;
        countWindow[B[i]]++;
        if(areEqual(countA, countWindow)) result++;
    }
    
    cout << result;
    return 0;
}