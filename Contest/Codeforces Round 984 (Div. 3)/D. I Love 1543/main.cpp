#include <iostream>
#include <vector>
#include <string>

using namespace std;

void traverseLayer(vector<string>& carpet, int n, int m, int layer, string& path) {
    // Traverse top row from left to right
    for (int j = layer; j < m - layer; ++j) {
        path += carpet[layer][j];
    }
    // Traverse right column from top to bottom
    for (int i = layer + 1; i < n - layer; ++i) {
        path += carpet[i][m - layer - 1];
    }
    // Traverse bottom row from right to left
    for (int j = m - layer - 2; j >= layer; --j) {
        path += carpet[n - layer - 1][j];
    }
    // Traverse left column from bottom to top
    for (int i = n - layer - 2; i > layer; --i) {
        path += carpet[i][layer];
    }
}

int count1543(const string& path) {
    int count = 0;
    for (size_t i = 0; i + 3 < path.size(); ++i) {
        if (path.substr(i, 4) == "1543") {
            ++count;
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

        int totalCount = 0;
        int layers = min(n, m) / 2;
        for (int layer = 0; layer < layers; ++layer) {
            string path;
            traverseLayer(carpet, n, m, layer, path);
            totalCount += count1543(path);
        }

        cout << totalCount << endl;
    }
    return 0;
}
