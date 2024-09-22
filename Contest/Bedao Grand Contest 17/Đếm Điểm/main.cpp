/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

// Function to check if a point is inside or on the circle
bool isInsideOrOnCircle(int x, int y, int r) {
    return x*x + y*y <= r*r;
}

// Function to count the total weight of points inside the circle
int countPointsInCircle(const vector<tuple<int, int, int>>& points, int r) {
    int count = 0;
    for (const auto& point : points) {
        int x, y, w;
        tie(x, y, w) = point;
        if (isInsideOrOnCircle(x, y, r)) {
            count += w;
        }
    }
    return count;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        points[i] = make_tuple(x, y, w);
    }

    vector<int> results;
    for (int j = 0; j < q; j++) {
        int r;
        cin >> r;
        results.push_back(countPointsInCircle(points, r));
    }

    // Output the results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}