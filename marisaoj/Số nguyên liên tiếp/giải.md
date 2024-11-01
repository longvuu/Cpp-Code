# Hướng Dẫn

## Mô tả bài toán
Bài toán yêu cầu tìm số lượng phần tử tối đa trong một dãy con liên tiếp của mảng `a` sao cho các phần tử trong dãy con này là các số nguyên liên tiếp. Sau đó, in ra số lượng phần tử cần thay đổi để biến dãy con này thành dãy liên tiếp có độ dài `n`.

## Giải thích thuật toán
Đầu tiên, ta sắp xếp mảng `a`, sau đó loại bỏ các giá trị trùng lặp để tạo ra một mảng mới chỉ gồm các giá trị duy nhất và giữ nguyên thứ tự ban đầu.

Giả sử `a` là mảng mới sau khi thực hiện các thao tác trên. Bây giờ, với mỗi giá trị `a[i]`, ta sẽ giả sử rằng dãy liên tiếp của chúng ta bắt đầu từ giá trị `a[i]` đến `a[i] + n - 1`. Ta cần xác định số lượng phần tử trong mảng `a` nằm trong khoảng `[a[i], a[i] + n - 1]`.

Do mảng `a` đã được sắp xếp và không có giá trị trùng lặp, ta có thể sử dụng tìm kiếm nhị phân để đếm số lượng phần tử trong khoảng này. Giả sử có `k` phần tử như vậy, ta sẽ không cần thay đổi những giá trị xuất hiện trong đoạn `[a[i], a[i] + n - 1]`. Vậy số lượng phần tử cần thay đổi sẽ là `n - k`.

Ta thực hiện thao tác trên với mỗi giá trị `a[i]` và chọn ra kết quả tốt nhất.



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