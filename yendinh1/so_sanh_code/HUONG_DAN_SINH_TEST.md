# Hướng dẫn sinh test cho các loại đề bài khác nhau

## 1. Bài toán số học cơ bản

### Ví dụ: Tính tổng, hiệu, tích, chia
```cpp
// Sinh 2 số nguyên a, b
int a = Rand(1, 1000);
int b = Rand(1, 1000);
inp << a << " " << b << "\n";
```

### Ví dụ: Tìm ước chung lớn nhất (GCD)
```cpp
// Sinh 2 số có thể lớn
long long a = Rand(1, 1000000);
long long b = Rand(1, 1000000);
inp << a << " " << b << "\n";
```

## 2. Bài toán mảng/dãy số

### Mảng số nguyên ngẫu nhiên
```cpp
int n = Rand(1, 100);  // Kích thước mảng
inp << n << "\n";
for(int i = 0; i < n; i++) {
    int x = Rand(1, 1000);  // Giá trị từ 1 đến 1000
    inp << x << (i == n-1 ? "\n" : " ");
}
```

### Mảng có thể có số âm
```cpp
int n = Rand(1, 50);
inp << n << "\n";
for(int i = 0; i < n; i++) {
    int x = Rand(-1000, 1000);  // Từ -1000 đến 1000
    inp << x << (i == n-1 ? "\n" : " ");
}
```

### Dãy số có tính chất đặc biệt (tăng dần)
```cpp
int n = Rand(1, 100);
inp << n << "\n";
vector<int> a(n);
for(int i = 0; i < n; i++) {
    a[i] = Rand(1, 1000);
}
sort(a.begin(), a.end());  // Sắp xếp tăng dần
for(int i = 0; i < n; i++) {
    inp << a[i] << (i == n-1 ? "\n" : " ");
}
```

## 3. Bài toán xâu (string)

### Xâu ký tự ngẫu nhiên
```cpp
int len = Rand(1, 100);  // Độ dài xâu
string s = "";
for(int i = 0; i < len; i++) {
    char c = 'a' + Rand(0, 25);  // Ký tự từ 'a' đến 'z'
    s += c;
}
inp << s << "\n";
```

### Xâu chỉ gồm 0 và 1
```cpp
int len = Rand(1, 50);
string s = "";
for(int i = 0; i < len; i++) {
    s += (Rand(0, 1) ? '1' : '0');
}
inp << s << "\n";
```

### Hai xâu để so sánh
```cpp
int len1 = Rand(1, 50);
int len2 = Rand(1, 50);
string s1 = "", s2 = "";
for(int i = 0; i < len1; i++) {
    s1 += char('a' + Rand(0, 25));
}
for(int i = 0; i < len2; i++) {
    s2 += char('a' + Rand(0, 25));
}
inp << s1 << "\n" << s2 << "\n";
```

## 4. Bài toán đồ thị

### Đồ thị vô hướng
```cpp
int n = Rand(3, 10);  // Số đỉnh
int m = Rand(1, n*(n-1)/2);  // Số cạnh
inp << n << " " << m << "\n";

set<pair<int,int>> edges;  // Tránh cạnh trùng
while(edges.size() < m) {
    int u = Rand(1, n);
    int v = Rand(1, n);
    if(u != v) {  // Không có khuyên
        if(u > v) swap(u, v);
        edges.insert({u, v});
    }
}
for(auto edge : edges) {
    inp << edge.first << " " << edge.second << "\n";
}
```

### Cây (tree)
```cpp
int n = Rand(2, 100);  // Số đỉnh
inp << n << "\n";
for(int i = 2; i <= n; i++) {
    int parent = Rand(1, i-1);  // Cha của đỉnh i
    inp << parent << " " << i << "\n";
}
```

### Đồ thị có hướng
```cpp
int n = Rand(2, 10);
int m = Rand(1, n*n);
inp << n << " " << m << "\n";
for(int i = 0; i < m; i++) {
    int u = Rand(1, n);
    int v = Rand(1, n);
    inp << u << " " << v << "\n";
}
```

## 5. Bài toán hình học

### Tọa độ điểm 2D
```cpp
int n = Rand(1, 100);  // Số điểm
inp << n << "\n";
for(int i = 0; i < n; i++) {
    int x = Rand(-1000, 1000);
    int y = Rand(-1000, 1000);
    inp << x << " " << y << "\n";
}
```

### Hình chữ nhật
```cpp
int x1 = Rand(-100, 100);
int y1 = Rand(-100, 100);
int x2 = Rand(x1, x1 + 100);  // Đảm bảo x2 >= x1
int y2 = Rand(y1, y1 + 100);  // Đảm bảo y2 >= y1
inp << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
```

## 6. Bài toán ma trận

### Ma trận vuông
```cpp
int n = Rand(2, 20);  // Kích thước ma trận
inp << n << "\n";
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        int x = Rand(1, 100);
        inp << x << (j == n-1 ? "\n" : " ");
    }
}
```

### Ma trận chữ nhật
```cpp
int n = Rand(1, 20);  // Số hàng
int m = Rand(1, 20);  // Số cột
inp << n << " " << m << "\n";
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        int x = Rand(0, 1);  // Ma trận 0-1
        inp << x << (j == m-1 ? "\n" : " ");
    }
}
```

## 7. Bài toán query (truy vấn)

### Nhiều truy vấn với các loại khác nhau
```cpp
int n = Rand(1, 100);  // Kích thước dữ liệu
int q = Rand(1, 50);   // Số truy vấn
inp << n << " " << q << "\n";

// Dữ liệu ban đầu
for(int i = 0; i < n; i++) {
    int x = Rand(1, 1000);
    inp << x << (i == n-1 ? "\n" : " ");
}

// Các truy vấn
for(int i = 0; i < q; i++) {
    int type = Rand(1, 3);  // 3 loại truy vấn
    if(type == 1) {
        // Loại 1: Cập nhật
        int pos = Rand(1, n);
        int val = Rand(1, 1000);
        inp << type << " " << pos << " " << val << "\n";
    } else if(type == 2) {
        // Loại 2: Truy vấn khoảng
        int l = Rand(1, n);
        int r = Rand(l, n);
        inp << type << " " << l << " " << r << "\n";
    } else {
        // Loại 3: Truy vấn đơn
        int pos = Rand(1, n);
        inp << type << " " << pos << "\n";
    }
}
```

## 8. Bài toán đặc biệt

### Bài toán palindrome
```cpp
int len = Rand(1, 100);
string s = "";
// Sinh một nửa đầu
for(int i = 0; i < (len + 1) / 2; i++) {
    s += char('a' + Rand(0, 25));
}
// Tạo palindrome
string full = s;
string rev = s;
reverse(rev.begin(), rev.end());
if(len % 2 == 0) {
    full += rev;
} else {
    full += rev.substr(1);
}
inp << full << "\n";
```

### Dãy Fibonacci
```cpp
int n = Rand(1, 20);  // Số thứ tự Fibonacci
inp << n << "\n";
```

### Số nguyên tố
```cpp
// Sinh số có thể là nguyên tố
int n = Rand(2, 1000);
inp << n << "\n";
```

## 9. Tips và lưu ý

### Kiểm soát kích thước test
```cpp
// Với bài khó, giảm kích thước để chạy nhanh
int n = Rand(1, (iTest <= 50) ? 10 : 100);  // Test đầu nhỏ, test sau lớn
```

### Tạo test edge case
```cpp
if(iTest == 1) {
    // Test case nhỏ nhất
    inp << "1\n1\n";
} else if(iTest == 2) {
    // Test case lớn nhất
    inp << "100000\n";
    for(int i = 0; i < 100000; i++) {
        inp << "1000000 ";
    }
    inp << "\n";
} else {
    // Test case ngẫu nhiên bình thường
    // ... code sinh test thông thường
}
```

### Đảm bảo tính hợp lệ
```cpp
// Với mảng con liên tiếp
int n = Rand(1, 100);
int l = Rand(1, n);
int r = Rand(l, n);  // Đảm bảo l <= r
inp << n << " " << l << " " << r << "\n";
```

## 10. Template tổng quát

```cpp
// Trong hàm main của sosanh.cpp
for (int iTest = 1; iTest <= NTEST; iTest++)
{
    ofstream inp((NAME + ".inp").c_str());
    
    // Chọn loại test dựa vào iTest
    if(iTest <= 10) {
        // Test nhỏ
    } else if(iTest <= 50) {
        // Test trung bình
    } else {
        // Test lớn
    }
    
    inp.close();
    // ... phần còn lại không đổi
}
```

Nhớ điều chỉnh các tham số `Rand()` cho phù hợp với giới hạn đề bài!
