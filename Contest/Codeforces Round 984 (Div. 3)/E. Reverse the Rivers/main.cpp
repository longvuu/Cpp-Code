/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<vector<int>> a(n, vector<int>(k));
    vector<vector<int>> b(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < k; ++j) {
        b[0][j] = a[0][j];
        for (int i = 1; i < n; ++i) {
            b[i][j] = b[i-1][j] | a[i][j];
        }
    }
    vector<vector<int>> prefix_min(n, vector<int>(k, INT_MAX));
    vector<vector<int>> prefix_max(n, vector<int>(k, INT_MIN));
    for (int j = 0; j < k; ++j) {
        prefix_min[0][j] = b[0][j];
        prefix_max[0][j] = b[0][j];
        for (int i = 1; i < n; ++i) {
            prefix_min[i][j] = min(prefix_min[i-1][j], b[i][j]);
            prefix_max[i][j] = max(prefix_max[i-1][j], b[i][j]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        vector<pair<int, pair<char, int>>> requirements(m);
        
        for (int j = 0; j < m; ++j) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            requirements[j] = {r-1, {o, c}};
        }
        
        int suitable_country = -1;
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            bool suitable = true;
            for (const auto& req : requirements) {
                int r = req.first;
                char o = req.second.first;
                int c = req.second.second;
                if (o == '<' && prefix_min[mid][r] >= c) {
                    suitable = false;
                    break;
                }
                if (o == '>' && prefix_max[mid][r] <= c) {
                    suitable = false;
                    break;
                }
            }
            if (suitable) {
                suitable_country = mid + 1;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << suitable_country << endl;
    }
    
    return 0;
}
