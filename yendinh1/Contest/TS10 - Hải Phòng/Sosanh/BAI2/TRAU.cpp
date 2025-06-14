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
    ll n;
    string st;
    cin >> n;
    cin >> st;
    ll maxLength = 0;
    for (int l = 0; l < n; l++) {
        int countA = 0, countU = 0, countG = 0, countC = 0;
        for (int r = l; r < n; r++) {
            if (st[r] == 'A') countA++;
            else if (st[r] == 'U') countU++;
            else if (st[r] == 'G') countG++;
            else if (st[r] == 'C') countC++;
            int subarrayLength = r - l + 1;
            int required = (subarrayLength / 2) + 1; 
            int matchCount = 0;
            if (countA == required) matchCount++;
            if (countU == required) matchCount++;
            if (countG == required) matchCount++;
            if (countC == required) matchCount++;
            
            if (matchCount == 1) {
                maxLength = max(maxLength, (ll)subarrayLength);
            }
        }
    }
    
    cout << maxLength << endl;
    return 0;
}