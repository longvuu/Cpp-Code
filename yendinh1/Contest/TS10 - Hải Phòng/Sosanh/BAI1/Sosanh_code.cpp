#include <bits/stdc++.h>
using namespace std;
const int NTEST = 200;

int main() {
    int d = 0;
    for (int i = 1; i <= NTEST; i++) {
        srand(i);
        ofstream fo("XDB.inp");
        int R1 = rand() % 20 + 1; // test nhỏ cho code trâu
        int R2 = R1 + rand() % 20 + 1;
        fo << R1 << " " << R2 << endl;
        fo.close();

        system("copy XDB.inp <nul >nul");
        system("FULL.exe < XDB.inp > FULL.out");
        system("TRAU.exe < XDB.inp > TRAU.out");

        if (system("fc FULL.out TRAU.out > nul") != 0)
            cout << "Test " << i << ": SAI!\n";
        else
            d++;
    }
    cout << d << "/" << NTEST << " Dung";
    return 0;
}