#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cstdlib> // cho system()

int main() {
    const int n = 100000;
    const long long k = 1000000000;
    int num_tests = 3; // số lượng test muốn tạo

    for (int t = 1; t <= num_tests; ++t) {
        std::vector<int> a(n);
        int max_a = k / n;

        std::mt19937 rng(42 + t); // seed khác nhau cho mỗi test
        std::uniform_int_distribution<int> dist(1, max_a);

        for (int i = 0; i < n; ++i) {
            a[i] = dist(rng);
        }

        std::string filename = "test" + std::to_string(t) + ".txt";
        std::ofstream fout(filename);
        fout << n << " " << k << "\n";
        int L = n;
        fout << L << "\n";
        for (int i = 0; i < n; ++i) {
            fout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
        fout.close();

        std::cout << "Tạo file " << filename << " thành công!\n";
        // Mở file vừa tạo (Windows)
        system(("start " + filename).c_str());
    }
    return 0;
}