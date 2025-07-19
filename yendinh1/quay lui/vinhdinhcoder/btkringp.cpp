#include <bits/stdc++.h>
#define taskname "btkringp"
using namespace std;
int n;
vector<int> a;      
vector<bool> s;     
vector<bool> isPrime;  

void sangnt(int N) {
    isPrime.assign(2 * N + 2, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 2 * N + 1; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= 2 * N + 1; j += i)
                isPrime[j] = false;
}

void quaylui(int i) {
    if (i == 2 * n) {
        if (isPrime[a[0] + a[2 * n - 1]]) {
            for (int v = 0; v < 2 * n; v++)
                cout << a[v] << (v + 1 == 2 * n ? "\n" : " ");
        }
        return;
    }
    for (int v = 2; v <= 2 * n; v++) {
        if (!s[v] && isPrime[a[i - 1] + v]) {
            s[v] = true;
            a[i] = v;
            quaylui(i + 1);
            s[v] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    sangnt(2 * n);
    a.assign(2 * n, 0);
    s.assign(2 * n + 1, false);
    a[0] = 1;
    s[1] = true;
    quaylui(1);
    return 0;
}