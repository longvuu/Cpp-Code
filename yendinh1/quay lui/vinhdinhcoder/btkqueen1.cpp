/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkqueen1"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool isSafe(int r, int c, const vector<pair<int,int>>& q) {
    for (auto [x, y] : q) {
        if (x == r || y == c || abs(x - r) == abs(y - c))
            return false;
    }
    return true;
}

void backtrack(int r, int fx, int fy, vector<pair<int,int>>& q, vector<pair<int,int>>& res, bool& f) {
    if (f) return;
    if (q.size() == 8) {
        for (auto [x, y] : q) {
            if (!(x == fx && y == fy))
                res.push_back({x, y});
        }
        f = true;
        return;
    }
    if (r > 8) return;
    if (r == fx) {
        backtrack(r + 1, fx, fy, q, res, f);
        return;
    }
    for (int c = 1; c <= 8; c++) {
        if (isSafe(r, c, q)) {
            q.push_back({r, c});
            backtrack(r + 1, fx, fy, q, res, f);
            if (f) return;
            q.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int fx, fy;
    cin >> fx >> fy;
    vector<pair<int,int>> q;
    q.push_back({fx, fy});

    vector<pair<int,int>> res;
    bool f = false;

    backtrack(1, fx, fy, q, res, f);
    for (auto [r, c] : res) cout << r << " " << c << "\n";
    return 0;
}