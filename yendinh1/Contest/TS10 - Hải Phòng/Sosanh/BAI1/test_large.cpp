#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
    
    // Test với các giá trị khác nhau
    vector<long long> test_values = {1000000, 10000000, 50000000};
    
    for (long long R : test_values) {
        cout << "Testing with R = " << R << endl;
        
        auto start = high_resolution_clock::now();
        long long result = countPointsInCircle(R);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Result: " << result << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        cout << "-------------------------" << endl;
    }
    
    // Ước tính thời gian cho R = 1e8
    cout << "Estimate for R = 1e8:" << endl;
    cout << "Expected iterations: " << 2e8 + 1 << endl;
    cout << "Estimated time: 200-500 milliseconds" << endl;
    
    return 0;
}
