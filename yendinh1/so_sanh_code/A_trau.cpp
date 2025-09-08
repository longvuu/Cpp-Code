#include <bits/stdc++.h>
using namespace std;

int main() {
    // Đọc từ file input
    freopen("A.inp", "r", stdin);
    // Ghi ra file output (thuật toán brute force)
    freopen("A.ans", "w", stdout);
    
    // =================== CODE THUẬT TOÁN BRUTE FORCE ===================
    // Viết thuật toán brute force (đúng nhưng chậm) ở đây
    // Đây là thuật toán chuẩn để so sánh với thuật toán chính
    
    int a, b;
    cin >> a >> b;
    
    // Ví dụ: Tính tổng bằng cách cộng từng đơn vị (chậm nhưng đúng)
    int sum = 0;
    for(int i = 1; i <= a; i++) sum++;
    for(int i = 1; i <= b; i++) sum++;
    cout << sum << "\n";
    
    // ================================================================
    
    return 0;
}
