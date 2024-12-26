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

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll N;
    cin >> N;
    
    ll M = (N % 2 == 0) ? N / 2 : N / 2 + 1;
    cout << M << endl;
    
    vector<vector<char>> a(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            a[i][j] = 'A' + (i + j) % N;
        }
    }
    
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < M; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}