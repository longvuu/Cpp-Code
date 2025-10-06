/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int T;
    cin >> T;
    while(T--) {
        long long n,rK,cK,rD,cD; 
        cin >> n >> rK >> cK >> rD >> cD;
        long long ans = 1; 
        long long dr = rK - rD;
        long long dc = cK - cD;
        if(dr > 0) ans = max(ans, dr + (n - rK)); 
        if(dr < 0) ans = max(ans, -dr + rK);       
        if(dc > 0) ans = max(ans, dc + (n - cK));  
        if(dc < 0) ans = max(ans, -dc + cK);       
        cout << ans << '\n';
    }
    return 0;
}