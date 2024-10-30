# Hướng Dẫn 

## Mô tả bài toán
Cho một mảng A gồm các phần tử nguyên với độ dài n và có q truy vấn. Mỗi truy vấn có dạng i, x, yêu cầu chèn giá trị x vào vị trí i của mảng A. Sau mỗi truy vấn, in ra mảng A.

## Giải thuật

1. **Khởi tạo mảng**: Đọc số nguyên `n` và `q` từ đầu vào. Tạo một mảng `A` với `n` phần tử từ đầu vào.
2. **Thực hiện các truy vấn**:
    - Đọc số nguyên `i` và `x` từ đầu vào.
    - Chèn giá trị `x` vào vị trí `i` của mảng `A`.
    - In ra mảng `A` sau khi chèn.

## Độ phức tạp
- Độ phức tạp thời gian của thuật toán là `O(n + q * m)`, trong đó `m` là kích thước trung bình của mảng sau mỗi truy vấn. Điều này là do việc chèn vào vector có độ phức tạp trung bình là `O(m)`.

## Code
```cpp
/*
    author: longvuu
    github: kuronight29
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> A;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        A.push_back(x);
    }
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        A.insert(A.begin() + x-1, y);
        for (ll j = 0; j < A.size(); j++)
        {
            cout << A[j] << " ";
        }
        cout << endl;
    }
}

```
