# Hướng Dẫn

## Mô tả bài toán
Bài toán yêu cầu kiểm tra xem có tồn tại một tập con của mảng A có tổng bằng k hay không. Ta có thể giải quyết bằng cách sử dụng phương pháp duyệt tất cả các tập con có thể.

## Giải thích thuật toán
1. **Đọc đầu vào**: Đầu tiên, chương trình đọc số lượng phần tử `n` và giá trị `k` từ đầu vào, sau đó đọc mảng `a` có `n` phần tử.
2. **Duyệt tất cả các tập con**: 
   - Sử dụng vòng lặp từ `0` đến `2^n - 1` để duyệt qua tất cả các tập con có thể của mảng `a`. Mỗi số nguyên trong khoảng này đại diện cho một tập con.
   - Sử dụng phép toán bit để kiểm tra xem phần tử nào thuộc tập con hiện tại.
3. **Tính tổng**: Với mỗi tập con, tính tổng các phần tử thuộc tập con đó.
4. **Kiểm tra điều kiện**: Nếu tổng của tập con bằng `k`, đặt biến `check` thành `true` và thoát khỏi vòng lặp.
5. **In kết quả**: Sau khi duyệt qua tất cả các tập con, nếu `check` là `true`, in "YES", ngược lại in "NO".

## Độ phức tạp
- **Thời gian**: O(2^n) do ta phải duyệt qua tất cả các tập con có thể.
- **Không gian**: O(n) để lưu mảng đầu vào.

## Code
```cpp
/*
    author: longvuu
    github: kuronight29
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    bool check = false;
    for(ll i = 0; i < (1 << n); i++){
        ll sum = 0;
        for(ll j = 0; j < n; j++){
            if(i & (1 << j)){
                sum += a[j];
            }
        }
        if(sum == k){
            check = true;
            break;
        }
    }
    if(check){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
```
