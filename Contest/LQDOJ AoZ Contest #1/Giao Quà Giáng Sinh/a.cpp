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

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int N, Q;
    cin >> N;
    vector<pair<int, int>> a;
    a.reserve(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    
    cin >> Q;
    vector<ll> results;
    results.reserve(Q);
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        ll curr_sum = 0;
        #pragma GCC unroll 4
        for (const auto& [px, py] : a) {
            curr_sum += 2 * (abs(px - x) + abs(py - y));
        }
        results.push_back(curr_sum);
    }
    
    for (const auto& result : results) {
        cout << result << '\n';
    }
    return 0;
}