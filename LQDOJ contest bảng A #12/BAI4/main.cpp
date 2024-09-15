/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findNthSpecialOdd(ll N) {
    ll base = 1, count = 0, digits = 1;
    
    while (count + (1LL << (digits - 1)) < N) {
        count += 1LL << (digits - 1);
        base = (base * 10) + 1;
        digits++;
    }
    
    N -= count;
    ll result = base + 2 * (N - 1);
    
    while (digits > 1) {
        ll sum = 0;
        ll temp = result;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum % 2 == 1) break;
        result += 2;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;
    cout << findNthSpecialOdd(N) << '\n';
    return 0;
}
