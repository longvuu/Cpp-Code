#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100; // Số lượng test

int main() {
    int d = 0;
    string chars = "AUGC";
    for (int i = 1; i <= NTEST; i++) {
        srand(i);
        ofstream fo("XDB.inp");
        int n = rand() % 200000 + 1; // 1 <= n <= 2*10^5
        fo << n << '\n';
        for (int j = 0; j < n; j++) {
            char c = chars[rand() % 4];
            fo << c;
        }
        fo << '\n';
        fo.close();

        // Sinh output từ hai chương trình
        system("FULL.exe");
        system("TRAU.exe");

        // So sánh kết quả
        if (system("fc FULL.out TRAU.out > nul") != 0)
            cout << "Test " << i << ": SAI!\n";
        else
            d++;
    }
    cout << d << "/" << NTEST << " Dung";
    return 0;
}