#include <bits/stdc++.h>
using namespace std;
long long countPointsInCircle(long long R) {
    long long R2 = R*R;
    long long cnt = 0;
    for (long long x = -R; x <= R; x++) {
        long long x2 = x*x;
        if (x2 > R2) continue; 
        long long limit = R2 - x2;
        long long yMax = (long long)floorl(sqrtl((long double)limit));
        cnt += (2LL * yMax + 1LL);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long R1, R2;
    cin >> R1 >> R2; 
    long long ans = countPointsInCircle(R2) - countPointsInCircle(R1);
    cout << ans << "\n";

    return 0;
}