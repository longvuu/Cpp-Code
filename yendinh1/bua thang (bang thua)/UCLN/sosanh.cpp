#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int test = 100;
    int cnt_ok = 0, cnt_fail = 0;
    for (int t = 1; t <= test; ++t) {
        ofstream inp("test.inp");
        int n = rand() % 10 + 1;
        int q = rand() % 10 + 1;
        inp << n << " " << q << "\n";
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) {
            a[i] = rand() % 100 + 1;
            inp << a[i] << " ";
        }
        inp << "\n";
        for (int i = 1; i <= q; ++i) {
            int l = rand() % n + 1;
            int r = rand() % n + 1;
            if (l > r) swap(l, r);
            inp << l << " " << r << "\n";
        }
        inp.close();

        system("FULL.exe < test.inp > full.ans");
        system("TRAU.exe < test.inp > trau.ans");

        ifstream f1("full.ans"), f2("trau.ans");
        string s1, s2;
        bool ok = true;
        int line = 0;
        while (getline(f1, s1) && getline(f2, s2)) {
            ++line;
            if (s1 != s2) {
                cout << "Test " << t << ", dòng " << line << " sai!\n";
                cout << "FULL: " << s1 << "\n";
                cout << "TRAU: " << s2 << "\n";
                ok = false;
                break;
            }
        }
        if (ok && (getline(f1, s1) || getline(f2, s2))) {
            cout << "Test " << t << " sai! Số dòng output khác nhau.\n";
            ok = false;
        }
        if (!ok) {
            cout << "Input gây lỗi đã được lưu ở test.inp\n";
            cnt_fail++;
        } else {
            cnt_ok++;
        }
    }
    cout << "Done!\n";
    cout << "Số test đúng: " << cnt_ok << "\n";
    cout << "Số test sai: " << cnt_fail << "\n";
    return 0;
}