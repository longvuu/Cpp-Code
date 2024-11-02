/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

bool isPerfectMelody(const vector<int>& melody) {
    for (size_t i = 1; i < melody.size(); ++i) {
        int interval = abs(melody[i] - melody[i - 1]);
        if (interval != 5 && interval != 7) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> melody(n);
        for (int i = 0; i < n; ++i) {
            cin >> melody[i];
        }
        if (isPerfectMelody(melody)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
