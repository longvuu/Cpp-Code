/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "invert"
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
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        int count = 0;
        for(int i = l; i < r; i++) {
            for(int j = i + 1; j <= r; j++) {
                if(a[i] > a[j]) {
                    count++;
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}