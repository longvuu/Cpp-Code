/*
    @author longvuuuu
    Bài toán: Tìm tập con các tờ tiền có tổng bằng M
*/
#include <bits/stdc++.h>
#define taskname "btkcayatm"
#define ll long long
using namespace std;

int n;
ll m;
vector<ll> T;
vector<int> ketqua;
bool timthay = false;

void inKetQua() {
    cout << ketqua.size() << "\n";
    for (int i = 0; i < ketqua.size(); i++) {
        cout << ketqua[i] + 1;
        if (i < ketqua.size() - 1) cout << " ";
    }
    cout << "\n";
}

void quayLui(int viTri, ll tongHienTai) {
    // Nếu đã tìm thấy kết quả thì dừng
    if (timthay) return;
    
    // Nếu tổng bằng m thì in kết quả
    if (tongHienTai == m) {
        inKetQua();
        timthay = true;
        return;
    }
    
    // Nếu vượt quá số tờ tiền hoặc tổng vượt quá m thì dừng
    if (viTri >= n || tongHienTai > m) return;
    
    // Thử chọn tờ tiền thứ viTri
    if (tongHienTai + T[viTri] <= m) {
        ketqua.push_back(viTri);
        quayLui(viTri + 1, tongHienTai + T[viTri]);
        ketqua.pop_back();
    }
    
    // Thử không chọn tờ tiền thứ viTri
    quayLui(viTri + 1, tongHienTai);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Đọc file nếu có
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    // Đọc dữ liệu
    cin >> n >> m;
    T.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    
    // Gọi hàm quay lui
    quayLui(0, 0);
    
    // Nếu không tìm thấy kết quả
    if (!timthay) {
        cout << "khongtherut\n";
    }
    
    return 0;
}