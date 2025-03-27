Giải thích thuật toán
Bài toán yêu cầu tìm số nguyên dương nhỏ nhất \( m \) sao cho \( k \times m \) là một số chỉ chứa một chữ số lặp lại (ví dụ: 111, 222, 99999).

Ý tưởng chính
Một số có tất cả các chữ số giống nhau có thể biểu diễn dưới dạng \( c = p \times j \), trong đó:

- \( p \) có dạng 1, 11, 111, 1111, ..., 111111111 (có tối đa 9 chữ số 1).
- \( j \) là một chữ số từ 1 đến 9 để tạo ra các số như 111, 222, ..., 999999999.

Nếu tồn tại \( c \) chia hết cho \( k \), thì ta có thể tính \( m = \frac{c}{k} \).

Mục tiêu là tìm \( m \) nhỏ nhất.

Chi tiết thuật toán
Sinh các số có chữ số giống nhau

Duyệt qua các số có dạng \( p = 1, 11, 111, ..., 111111111 \) bằng cách đặt:

\( p = p \times 10 + 1 \)

Với mỗi \( p \), nhân với các số từ 9 đến 1 để tạo ra các số có chữ số giống nhau:

\( c = p \times j \)

Ví dụ:

- \( p = 111 \), khi nhân với 2 → \( c = 222 \)
- \( p = 11111 \), khi nhân với 7 → \( c = 77777 \)

Kiểm tra chia hết cho \( k \)

Nếu \( c \) chia hết cho \( k \), ta tìm được \( m \):

\( m = \frac{c}{k} \)

So sánh với giá trị nhỏ nhất của \( m \) đã tìm được để cập nhật kết quả.

Xuất kết quả

Do \( m \) có thể rất lớn, nên ta chỉ cần in phần dư của \( m \) khi chia cho \( 10^9 + 7 \).
