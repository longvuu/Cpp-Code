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
    // Test với R nhỏ trước
    cout << "Testing with small R values:\n";
    cout << "R = 1000: " << countPointsInCircle(1000) << endl;
    cout << "R = 10000: " << countPointsInCircle(10000) << endl;
    
    // Test với R lớn hơn
    cout << "\nTesting with larger R values:\n";
    auto start = chrono::high_resolution_clock::now();
    cout << "R = 1000000: " << countPointsInCircle(1000000);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << " (Time: " << duration.count() << "ms)" << endl;
    
    // Test với R = 10^7 (10 triệu)
    start = chrono::high_resolution_clock::now();
    cout << "R = 10000000: " << countPointsInCircle(10000000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << " (Time: " << duration.count() << "ms)" << endl;
    
    // Ước tính thời gian cho R = 10^8
    cout << "\nEstimated time for R = 100000000: " << duration.count() * 10 << "ms" << endl;
    
    return 0;
}
