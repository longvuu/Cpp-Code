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

int countFibonacciness(int a1, int a2, int a3, int a4, int a5) {
    int count = 0;
    if (a3 == a1 + a2) count++;
    if (a4 == a2 + a3) count++;
    if (a5 == a3 + a4) count++;
    return count;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int t;
    cin >> t;
    while(t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        
        int maxFib = 0;
        vector<int> possibleA3 = {a4 - a2, a5 - a4, a1 + a2};
        for(int a3 : possibleA3) {
            maxFib = max(maxFib, countFibonacciness(a1, a2, a3, a4, a5));
        }
        cout << maxFib << "\n";
    }
    
    return 0;
}