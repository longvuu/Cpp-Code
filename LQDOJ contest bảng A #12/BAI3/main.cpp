/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    // Tính số lần cắt cần thiết
    long long cuts = (x - y) / (y - 1);
    if ((x - y) % (y - 1) != 0) {
        cuts++; // Nếu còn dư, cần thêm 1 lần cắt
    }

    cout << cuts << endl;
    return 0;
}
