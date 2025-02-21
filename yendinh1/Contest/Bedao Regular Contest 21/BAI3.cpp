/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int K = min(n, 2000);
    
    unordered_map<long long, pair<int,int>> seen;
    seen.reserve(K * (K-1) / 2);
    seen.max_load_factor(0.7f);

    for (int i = 1; i <= K; i++) {
        for (int j = i + 1; j <= K; j++) {
            long long sum = a[i] + a[j];
            
            if (seen.find(sum) != seen.end()) {
                auto [x, y] = seen[sum];
                if (x != i && x != j && y != i && y != j) {
                    cout << x << " " << y << " " << i << " " << j << "\n";
                    return 0;
                }
            } else {
                seen[sum] = {i, j};
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}