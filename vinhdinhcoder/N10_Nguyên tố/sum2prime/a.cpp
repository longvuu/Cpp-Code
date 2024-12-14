/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "sum2prime"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
vector<bool> is_prime(1000001, true);
void sangnt() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    bool kt =false;
    while(kt == false) {
        for (int i = 2; i <= n / 2; i++) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << i << " " << n - i;
                kt = true;
                break;
            }
        }
        if (kt == false) n++;
    }
   
    
    return 0;
}