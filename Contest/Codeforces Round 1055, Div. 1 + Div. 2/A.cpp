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
        int n; cin >> n;
         vector<int> a(n); 
         for(int &x: a) cin >> x;
        sort(a.begin(), a.end());
        int M = a.back();
        int m = 0;
        for(int i=0;i<n-1;i++) if(a[i] != a[i+1] && a[i] != M) m++;
        if(n==1) m = (a[0]==M?0:m); 
        cout << (2LL*m + 1) << '\n';
    }
    return 0;
}