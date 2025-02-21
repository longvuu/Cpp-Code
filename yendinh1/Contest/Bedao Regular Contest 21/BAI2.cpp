#include <bits/stdc++.h>
using namespace std;
static const int INF = -1;

int dp[27][100001];
bool used[27][100001];  // Fixed missing closing bracket here
vector<int> posOf[26];
string s;
int n;

int getLastIndexIfPick(int letter, int startPos) {
    int needed = letter + 1; // số lượng ký tự cần
    auto &arr = posOf[letter];
    auto it = std::lower_bound(arr.begin(), arr.end(), startPos);
    if (it == arr.end()) return -1; 
    if ( (it + needed - 1) >= arr.end() ) return -1;
    int lastIdx = *(it + (needed - 1));
    return lastIdx;
}

// Hàm đệ quy top-down
int solveDP(int letter, int pos) {
    if (letter == 26) {
        return 0;
    }
    if (used[letter][pos]) {
        return dp[letter][pos];
    }
    used[letter][pos] = true;

    int res = solveDP(letter + 1, pos);

    int lastIdx = getLastIndexIfPick(letter, pos);
    if (lastIdx != -1) {
        int lengthIfPick = (letter + 1) 
                           + solveDP(letter + 1, lastIdx + 1);
        res = max(res, lengthIfPick);
    }

    dp[letter][pos] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = (int)s.size();
    for(int c = 0; c < 26; c++){
        posOf[c].clear();
    }
    for(int i = 0; i < n; i++){
        char c = s[i];
        posOf[c - 'a'].push_back(i);
    }
    memset(used, false, sizeof(used));
    int ans = solveDP(0, 0);
    cout << ans << "\n";

    return 0;
}
