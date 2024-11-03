/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>

using namespace std;

bool check1100(const string &s, int pos) {
    return pos >= 0 && pos + 3 < s.size() && s.substr(pos, 4) == "1100";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }

        unordered_set<int> positions;
        for (size_t i = 0; i + 3 < s.size(); ++i) {
            if (s.substr(i, 4) == "1100") {
                positions.insert(i);
            }
        }

        for (const auto &query : queries) {
            int i = query.first - 1;
            int v = query.second;
            for (int j = i - 3; j <= i; ++j) {
                if (check1100(s, j)) {
                    positions.erase(j);
                }
            }
            s[i] = '0' + v;
            for (int j = i - 3; j <= i; ++j) {
                if (check1100(s, j)) {
                    positions.insert(j);
                }
            }
            if (!positions.empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
