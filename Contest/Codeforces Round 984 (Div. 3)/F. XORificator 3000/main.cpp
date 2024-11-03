/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll up_xor(ll n) {
    if (n < 0) {
        return 0;
    }
    ll mod = n % 4;
    if (mod == 0) {
        return n;
    } else if (mod == 1) {
        return 1;
    } else if (mod == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        ll sh = 1 << i;

        ll sum = up_xor(r) ^ up_xor(l - 1);

        ll start = (l - k + sh - 1) / sh;
        ll end = (r - k) / sh;

        ll xor_val;
        if (start > end) {
            xor_val = 0;
        } else {
            ll num = end - start + 1;
            ll sh_xor = up_xor(end) ^ up_xor(start - 1);
            xor_val = (sh_xor << i);
            if (num % 2 == 1) {
                xor_val ^= k;
            }
        }
        ll ans = sum ^ xor_val;
        cout << ans << endl;
    }
    return 0;
}
