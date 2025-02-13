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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y <= x + 1 && (x + 1 - y) % 9 == 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;
}
