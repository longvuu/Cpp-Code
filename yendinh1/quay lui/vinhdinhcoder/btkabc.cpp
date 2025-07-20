/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    int N;
    cin >> N;

    string res;
    int minC = N+1;
    string ans;

    // Optimized beautiful check - only checks the newly added character
    auto is_beautiful = [](const string& s) {
        int n = s.size();
        // Check each possible substring length
        for (int len = 1; len * 2 <= n; ++len) {
            // Compare the last 'len' characters with the previous 'len' characters
            bool match = true;
            for (int i = 0; i < len; ++i) {
                if (s[n - len + i] != s[n - 2*len + i]) {
                    match = false;
                    break;
                }
            }
            if (match) return false;
        }
        return true;
    };

    function<void(int,int)> backtrack = [&](int pos, int cntC) {
        // If we already have more C's than the current minimum, prune this branch
        if (cntC >= minC) return;
        
        // Found a complete solution
        if (pos == N) {
            minC = cntC;
            ans = res;
            return;
        }
        
        // Try characters in order A, B, C to prioritize solutions with fewer C's
        for (char ch : {'A','B','C'}) {
            res.push_back(ch);
            if (is_beautiful(res)) {
                backtrack(pos+1, cntC + (ch=='C'));
            }
            res.pop_back();
        }
    };

    backtrack(0,0);
    cout << ans << '\n';
    return 0;
}