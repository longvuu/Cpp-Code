#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // Use XOR queries to gather information
        long long totalXor = 0;
        for (long long i = 1; i <= n; i++) {
            totalXor ^= i;
        }

        long long xorAll = 0;
        for (long long i = 1; i <= n; i += n / 150) {
            long long l = i;
            long long r = min(n, i + n / 150 - 1);
            cout << "xor " << l << " " << r << endl;
            cout.flush();
            long long result;
            cin >> result;
            xorAll ^= result;
        }

        // Deduce the missing numbers a, b, and c
        long long xorMissing = totalXor ^ xorAll;
        long long a = 1, b = 2, c = xorMissing ^ 1 ^ 2; // Placeholder values

        cout << "ans " << a << " " << b << " " << c << endl;
        cout.flush();
    }
}

int main() {
    solve();
    return 0;
}
