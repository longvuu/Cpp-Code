#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "A";
// Số test kiểm tra
const int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện.
// Hàm random này sinh ngẫu nhiên số trong phạm vi long long
// Số sinh ra nằm trong [L;R].
long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        
        int a = Rand(1, 1000);
        int b = Rand(1, 1000);
        inp << a << " " << b << "\n"; 
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}