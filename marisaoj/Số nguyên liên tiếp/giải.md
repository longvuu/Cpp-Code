# Hướng Dẫn

## Mô tả bài toán
Bài toán yêu cầu tìm số lượng phần tử tối đa trong một dãy con liên tiếp của mảng `a` sao cho các phần tử trong dãy con này là các số nguyên liên tiếp. Sau đó, in ra số lượng phần tử cần thay đổi để biến dãy con này thành dãy liên tiếp có độ dài `n`.

## Giải thích thuật toán
1. **Đọc đầu vào**: Đầu tiên, chương trình đọc số lượng phần tử `n` từ đầu vào, sau đó đọc mảng `a` có `n` phần tử.
2. **Sắp xếp và loại bỏ phần tử trùng lặp**: 
    - Sắp xếp mảng `a` để dễ dàng tìm kiếm các dãy con liên tiếp.
    - Loại bỏ các phần tử trùng lặp trong mảng.
3. **Tìm dãy con liên tiếp dài nhất**: 
    - Duyệt qua từng phần tử `d` trong mảng `a`.
    - Tìm số lượng phần tử liên tiếp bắt đầu từ `d` và có độ dài tối đa `n`.
    - Cập nhật giá trị `ans` với độ dài dãy con liên tiếp dài nhất tìm được.
4. **In kết quả**: In ra `n - ans`, là số lượng phần tử cần thay đổi để biến dãy con này thành dãy liên tiếp có độ dài `n`.

## Độ phức tạp
- **Thời gian**: O(n log n) do sắp xếp mảng và sử dụng tìm kiếm nhị phân.
- **Không gian**: O(n) để lưu mảng đầu vào.

## Code
```cpp
/*
     @author longvuuuu
     @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
long long n;

int main(){
     cin >> n;
     a = vector<long long>(n);
     for(long long &d : a) 
          cin >> d;
     sort(a.begin(), a.end());
     a.erase(unique(a.begin(), a.end()), a.end());
     long long ans = 0;
     for(long long &d : a){
          ans = max(ans, (long long)(upper_bound(a.begin(), a.end(), d + n - 1) - lower_bound(a.begin(), a.end(), d)));
     }
     cout << n - ans;
}