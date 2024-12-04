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
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    vector<int> a = {1, 5, 8, 12, 15, 20, 25, 30, 35, 40, 45, 50};
    for(int x : a) cout << x << " ";
    cout << endl;
    for(int i = 0; i < a.size(); i += 3) {
        cout << a[i] << " ";
    }
    
    return 0;
}