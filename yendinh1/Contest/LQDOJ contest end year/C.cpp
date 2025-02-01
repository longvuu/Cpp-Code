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

double getAverage(vector<int>& indices, vector<int>& a, vector<int>& c) {
    double totalCost = 0, totalItems = 0;
    for(int idx : indices) {
        totalCost += c[idx];
        totalItems += a[idx];
    }
    return totalItems == 0 ? 0 : totalCost / totalItems;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<int> a(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    double minProduct = 1e18;
    vector<int> combination(n);

    fill(combination.begin(), combination.begin() + m, 1);
    fill(combination.begin() + m, combination.end(), 0);

    do {
        vector<int> shop1, shop2;
        for(int i = 0; i < n; i++) {
            if(combination[i]) shop1.pb(i);
            else shop2.pb(i);
        }

        double x1 = getAverage(shop1, a, c);
        double x2 = getAverage(shop2, a, c);

        if(x1 > 0 && x2 > 0) {
            minProduct = min(minProduct, x1 * x2);
        }
    } while(next_permutation(combination.begin(), combination.end()));

    cout << fixed << setprecision(3) << minProduct << '\n';
    return 0;
}
