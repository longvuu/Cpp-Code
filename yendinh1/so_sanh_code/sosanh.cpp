#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}
int main()
{
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("test.inp");
        int a = Rand(1, 1000);
        int b = Rand(1, 1000);
        inp << a << " " << b << "\n"; 
        inp.close();
        system("full.exe"); 
        system("trau.exe"); 
        if (system("fc test.out test.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}