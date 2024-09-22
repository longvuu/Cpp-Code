/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
// Function to check if a given x satisfies the equation for n and i
bool isValid(ll x, ll n, ll i) {
    ll sum = 1;
    ll term = 1;
    for (ll j = 1; j < i; j++) {
        term *= x;
        if (term > n) return false; // Prevent overflow
        sum += term;
        if (sum > n) return false; // Prevent overflow
    }
    return sum == n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        ll result = -1;
        for (ll i = 2; i <= 60; i++) { // 60 is a safe upper bound for steps
            ll low = 2, high = n;
            while (low <= high) {
                ll mid = low + (high - low) / 2;
                if (isValid(mid, n, i)) {
                    result = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (result != -1) break;
        }
        cout << result << endl;
    }
    return 0;
}