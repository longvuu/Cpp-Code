/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

bool isRepeatedDigitNumber(ll num) {
    string s = to_string(num);
    return s.front() == s.back();
}

pair<char, ll> findNthDigitAndNumber(ll N) {
    ll currentLength = 0;
    ll number = 0;

    while (true) {
        if (isRepeatedDigitNumber(number)) {
            string s = to_string(number);
            if (currentLength + s.size() >= N) {
                return {s[N - currentLength - 1], number};
            }
            currentLength += s.size();
        }
        number++;
    }
}

int main() {
    ll N;
    cin >> N;

    auto result = findNthDigitAndNumber(N);
    cout << result.first << " " << result.second << endl;

    return 0;
}
