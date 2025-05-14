# Kiến thức tìm kiếm nhị phân

## 1. Khái niệm

Tìm kiếm nhị phân (Binary Search) là một thuật toán tìm kiếm trên mảng (hoặc dãy số) đã được sắp xếp. Thuật toán này hoạt động bằng cách liên tục chia đôi khoảng tìm kiếm cho đến khi tìm được phần tử cần tìm hoặc xác định rằng phần tử đó không tồn tại.

## 2. Điều kiện áp dụng

- Dữ liệu phải được **sắp xếp** (tăng dần hoặc giảm dần).
- Có thể áp dụng trên mảng, vector, list, hoặc các bài toán tìm giá trị thỏa mãn điều kiện trong một đoạn.

## 3. Ý tưởng thuật toán

1. Xác định hai chỉ số `left` (l) và `right` (r) đại diện cho đoạn tìm kiếm.
2. Trong khi `left <= right`:
   - Tính chỉ số giữa: `mid = (left + right) / 2`
   - So sánh giá trị tại `mid` với giá trị cần tìm:
     - Nếu bằng, trả về kết quả.
     - Nếu nhỏ hơn, tìm kiếm nửa phải (`left = mid + 1`).
     - Nếu lớn hơn, tìm kiếm nửa trái (`right = mid - 1`).
3. Nếu không tìm thấy, trả về -1 hoặc thông báo không tồn tại.

## 4. Cài đặt cơ bản (C++)

```cpp
int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Không tìm thấy
}
```

## 5. Các biến thể

- **Tìm kiếm nhị phân trên đáp án**: Dùng để tìm giá trị nhỏ nhất/lớn nhất thỏa mãn điều kiện (ví dụ: tìm min/max, tìm số lớn nhất nhỏ hơn hoặc bằng x, tìm số nhỏ nhất lớn hơn hoặc bằng x).
- **Tìm vị trí đầu tiên/cuối cùng**: Tìm chỉ số đầu/cuối của một giá trị trong mảng có thể có nhiều phần tử giống nhau.

### Ví dụ: Tìm vị trí đầu tiên của x

```cpp
int lower_bound(int a[], int n, int x) {
    int left = 0, right = n - 1, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= x) {
            res = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    return res;
}
```

### Ví dụ: Tìm vị trí cuối cùng của x

```cpp
int upper_bound(int a[], int n, int x) {
    int left = 0, right = n - 1, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            res = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    return res;
}
```

## 6. Lưu ý khi sử dụng

- Cẩn thận với tràn số khi tính `mid` (nên dùng `mid = left + (right - left) / 2`).
- Đảm bảo mảng đã được sắp xếp.
- Kiểm tra điều kiện dừng vòng lặp (`left <= right` hoặc `left < right` tùy bài toán).
- Đối với tìm kiếm nhị phân trên đáp án, cần xác định rõ hàm kiểm tra điều kiện (predicate).

## 7. Các hàm hỗ trợ trong C++

### 7.1. std::lower_bound

- Tìm iterator đầu tiên có giá trị **không nhỏ hơn** (>=) x trong đoạn [first, last).
- Nếu không có, trả về iterator cuối.
- Cú pháp:
  ```cpp
  auto it = std::lower_bound(a, a + n, x);
  int pos = it - a; // vị trí trong mảng
  ```

### 7.2. std::upper_bound

- Tìm iterator đầu tiên có giá trị **lớn hơn** (>) x trong đoạn [first, last).
- Nếu không có, trả về iterator cuối.
- Cú pháp:
  ```cpp
  auto it = std::upper_bound(a, a + n, x);
  int pos = it - a;
  ```

### 7.3. std::binary_search

- Kiểm tra xem x có xuất hiện trong đoạn [first, last) không.
- Trả về true/false.
- Cú pháp:
  ```cpp
  bool found = std::binary_search(a, a + n, x);
  ```

### 7.4. Lưu ý

- Các hàm này yêu cầu mảng đã được **sắp xếp tăng dần**.
- Có thể sử dụng với vector, array, hoặc iterator bất kỳ.

## 8. Ứng dụng

- Tìm kiếm trong mảng, danh sách.
- Tìm nghiệm của phương trình đơn điệu.
- Tối ưu hóa đáp án trong các bài toán tối ưu (tìm min/max thỏa mãn điều kiện).
- Các bài toán trên dãy số, chuỗi, số nguyên, số thực.

## 9. Tài liệu tham khảo

- [GeeksforGeeks - Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [CP Algorithms - Binary Search](https://cp-algorithms.com/search.html)
