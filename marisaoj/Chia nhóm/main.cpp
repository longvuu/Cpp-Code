/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

bool backtrack(vector<int>& A, vector<int>& groups, int target, int idx) {
    if (idx == A.size()) return true;
    for (int i = 0; i < groups.size(); ++i) {
        if (groups[i] + A[idx] <= target) {
            groups[i] += A[idx];
            if (backtrack(A, groups, target, idx + 1)) return true;
            groups[i] -= A[idx];
        }
        if (groups[i] == 0) break; 
    }
    return false;
}

int main() {
    //freopen(taskname ".inp", "r", stdin);
    //freopen(taskname ".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % k != 0) {
        cout << "0" << endl;
        return 0;
    }
    int target = sum / k;
    vector<int> groups(k, 0);
    sort(A.rbegin(), A.rend()); 
    if (backtrack(A, groups, target, 0)) {
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (groups[j] >= A[i]) {
                    groups[j] -= A[i];
                    result[i] = j + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) cout << result[i] << " ";
        cout << endl;
    } else {
        cout << "ze" << endl;
    }
    return 0;
}