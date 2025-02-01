/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

void flipHorizontal(vector<vector<int>>& m1) {
    int n = m1.size();
    for (int i = 0; i < n; ++i) {
        reverse(m1[i].begin(), m1[i].end());
    }
}

void flipVertical(vector<vector<int>>& m1) {
    int n = m1.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(m1[i], m1[n - i - 1]);
    }
}

void rotateClockwise(vector<vector<int>>& m1) {
    int n = m1.size();
    vector<vector<int>> t1 = m1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m1[j][n - i - 1] = t1[i][j];
        }
    }
}

void rotateCounterClockwise(vector<vector<int>>& m1) {
    int n = m1.size();
    vector<vector<int>> t1 = m1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m1[n - j - 1][i] = t1[i][j];
        }
    }
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<vector<int>> m1(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m1[i][j];
        }
    }
    
    char o1;
    cin >> o1;
    
    if (o1 == 'X') {
        flipHorizontal(m1);
    } else if (o1 == 'Y') {
        flipVertical(m1);
    } else if (o1 == 'L') {
        rotateCounterClockwise(m1);
    } else if (o1 == 'R') {
        rotateClockwise(m1);
    }
    
    for (const auto& r1 : m1) {
        for (const auto& e1 : r1) {
            cout << e1 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}