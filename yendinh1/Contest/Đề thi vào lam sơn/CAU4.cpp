/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CAU4"
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string st;
    cin >> st;
    int n = st.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        vector<int> cnt(26, 0);
        for(int j = i; j < n; j++) {
            cnt[st[j] - 'a']++;
            int mx = *max_element(cnt.begin(), cnt.end());
            int sum = 0;
            for(int k = 0; k < 26; ++k) sum += cnt[k];
            if(mx > sum - mx) {
                if(j - i + 1 > res) res = j - i + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}