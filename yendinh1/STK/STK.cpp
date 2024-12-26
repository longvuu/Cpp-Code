/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "STK"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
int n;
int s[N]={0};
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    set<int> st;
    while(n!=0){
        st.insert(n%10);
        s[n%10]++;
        n/=10;
    }
    for(auto i : st) {
        cout << s[i] << i;
    }
    return 0;
}