/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;
int count1543(const vector<string>& carpet, int n, int m) {
    string target = "1543";
    int count = 0;
    for (int layer = 0; layer < (min(n, m) + 1) / 2; ++layer) {
        string layerString;
        for (int j = layer; j < m - layer; ++j) {
            layerString += carpet[layer][j];
        }
        for (int i = layer + 1; i < n - layer; ++i) {
            layerString += carpet[i][m - layer - 1];
        }
        if (n - layer - 1 > layer) {
            for (int j = m - layer - 2; j >= layer; --j) {
                layerString += carpet[n - layer - 1][j];
            }
        }
        // Left column
        if (m - layer - 1 > layer) {
            for (int i = n - layer - 2; i > layer; --i) {
                layerString += carpet[i][layer];
            }
        }
        size_t pos = layerString.find(target);
        while (pos != string::npos) {
            ++count;
            pos = layerString.find(target, pos + 1);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }
        cout << count1543(carpet, n, m) << endl;
    }
    return 0;
}