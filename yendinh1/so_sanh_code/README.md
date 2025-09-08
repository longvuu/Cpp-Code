# Hướng dẫn sử dụng Stress Testing

## Các file trong thư mục:

1. **`sosanh.cpp`** - Chương trình chính để so sánh
2. **`A.cpp`** - Thuật toán chính (tối ưu)
3. **`A_trau.cpp`** - Thuật toán brute force (chuẩn)
4. **`HUONG_DAN_SINH_TEST.md`** - Hướng dẫn sinh test chi tiết

## Cách sử dụng:

### Bước 1: Chỉnh sửa code sinh test
Mở file `sosanh.cpp` và chỉnh sửa phần code sinh test phù hợp với đề bài:
- Bỏ comment các template có sẵn
- Hoặc viết code sinh test tùy chỉnh

### Bước 2: Viết thuật toán
- **`A.cpp`**: Viết thuật toán tối ưu (nhanh)
- **`A_trau.cpp`**: Viết thuật toán brute force (đúng nhưng chậm)

### Bước 3: Compile và chạy
```bash
# Compile các file
g++ -o A.exe A.cpp
g++ -o A_trau.exe A_trau.cpp  
g++ -o sosanh.exe sosanh.cpp

# Chạy stress test
./sosanh.exe
```

### Bước 4: Xem kết quả
- Nếu tất cả test đều **CORRECT**: Thuật toán đúng
- Nếu có test **WRONG**: Kiểm tra file `A.inp`, `A.out`, `A.ans` để debug

## Lưu ý:
- Thay đổi `const string NAME = "A"` nếu muốn đổi tên file
- Điều chỉnh `const int NTEST = 100` để thay đổi số lượng test
- Đảm bảo thuật toán brute force luôn đúng (đây là chuẩn so sánh)

## Ví dụ output khi chạy:
```
Test 1: CORRECT!
Test 2: CORRECT!
...
Test 50: WRONG!
```

Nếu gặp lỗi ở test 50, kiểm tra:
- `A.inp`: Dữ liệu input của test 50
- `A.out`: Kết quả thuật toán chính
- `A.ans`: Kết quả thuật toán brute force (đúng)
