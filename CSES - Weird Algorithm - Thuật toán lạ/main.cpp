/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n;
int main() {
    //freopen(taskname ".inp", "r", stdin);
    //freopen(taskname ".out", "w", stdout);
    cin >> n;
    while(n!=1){
        cout << n << " ";
        if (n & 1LL)
            n = n * 3 + 1;
        else
            n /= 2;
    }
    cout << 1;
    return 0;
}