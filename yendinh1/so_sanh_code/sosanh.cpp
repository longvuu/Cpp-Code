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
        
        // =================== CHỌN LOẠI TEST PHÙ HỢP ===================
        
        // 1. BÀI TOÁN SỐ HỌC CỞ BẢN
        // int a = Rand(1, 1000);
        // int b = Rand(1, 1000);
        // inp << a << " " << b << "\n";
        
        // 2. BÀI TOÁN MẢNG/DÃY SỐ
        // int n = Rand(1, 100);
        // inp << n << "\n";
        // for(int i = 0; i < n; i++) {
        //     int x = Rand(1, 1000);
        //     inp << x << (i == n-1 ? "\n" : " ");
        // }
        
        // 3. BÀI TOÁN XÂU (STRING)
        // int len = Rand(1, 100);
        // string s = "";
        // for(int i = 0; i < len; i++) {
        //     char c = 'a' + Rand(0, 25);
        //     s += c;
        // }
        // inp << s << "\n";
        
        // 4. BÀI TOÁN ĐỒ THỊ VÔ HƯỚNG
        // int n = Rand(3, 10);  // Số đỉnh
        // int m = Rand(1, min(20, n*(n-1)/2));  // Số cạnh
        // inp << n << " " << m << "\n";
        // set<pair<int,int>> edges;
        // while(edges.size() < m) {
        //     int u = Rand(1, n);
        //     int v = Rand(1, n);
        //     if(u != v) {
        //         if(u > v) swap(u, v);
        //         edges.insert({u, v});
        //     }
        // }
        // for(auto edge : edges) {
        //     inp << edge.first << " " << edge.second << "\n";
        // }
        
        // 5. BÀI TOÁN CÂY (TREE)
        // int n = Rand(2, 100);
        // inp << n << "\n";
        // for(int i = 2; i <= n; i++) {
        //     int parent = Rand(1, i-1);
        //     inp << parent << " " << i << "\n";
        // }
        
        // 6. BÀI TOÁN MA TRẬN
        // int n = Rand(2, 20);
        // inp << n << "\n";
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         int x = Rand(1, 100);
        //         inp << x << (j == n-1 ? "\n" : " ");
        //     }
        // }
        
        // 7. BÀI TOÁN QUERY (TRUY VẤN)
        // int n = Rand(1, 100);
        // int q = Rand(1, 50);
        // inp << n << " " << q << "\n";
        // for(int i = 0; i < n; i++) {
        //     int x = Rand(1, 1000);
        //     inp << x << (i == n-1 ? "\n" : " ");
        // }
        // for(int i = 0; i < q; i++) {
        //     int type = Rand(1, 2);
        //     if(type == 1) {
        //         int pos = Rand(1, n);
        //         int val = Rand(1, 1000);
        //         inp << type << " " << pos << " " << val << "\n";
        //     } else {
        //         int l = Rand(1, n);
        //         int r = Rand(l, n);
        //         inp << type << " " << l << " " << r << "\n";
        //     }
        // }
        
        // 8. BÀI TOÁN HÌNH HỌC 2D
        // int n = Rand(1, 50);
        // inp << n << "\n";
        // for(int i = 0; i < n; i++) {
        //     int x = Rand(-1000, 1000);
        //     int y = Rand(-1000, 1000);
        //     inp << x << " " << y << "\n";
        // }
        
        // 9. BÀI TOÁN PERMUTATION (HOÁN VỊ)
        // int n = Rand(1, 10);
        // vector<int> p(n);
        // for(int i = 0; i < n; i++) p[i] = i + 1;
        // random_shuffle(p.begin(), p.end());
        // inp << n << "\n";
        // for(int i = 0; i < n; i++) {
        //     inp << p[i] << (i == n-1 ? "\n" : " ");
        // }
        
        // 10. TEST CASE ĐẶC BIỆT THEO THỨ TỰ
        // if(iTest <= 5) {
        //     // Test nhỏ
        //     int n = Rand(1, 10);
        //     inp << n << "\n";
        // } else if(iTest <= 80) {
        //     // Test trung bình
        //     int n = Rand(10, 100);
        //     inp << n << "\n";
        // } else {
        //     // Test lớn
        //     int n = Rand(100, 1000);
        //     inp << n << "\n";
        // }
        
        // =================== CODE SINH TEST CỦA BẠN ==================
        // Bỏ comment và chỉnh sửa phần code phù hợp với đề bài
        
        // Ví dụ mặc định: Tổng 2 số
        int a = Rand(1, 1000);
        int b = Rand(1, 1000);
        inp << a << " " << b << "\n";
        
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}