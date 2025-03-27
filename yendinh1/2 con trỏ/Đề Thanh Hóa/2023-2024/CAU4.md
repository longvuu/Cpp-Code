Tóm tắt cách làm
1. Phân tích bài toán
Có m vòng khóa, mỗi vòng chứa n số nguyên.

Mỗi vòng có thể xoay, tức là ta có thể chọn một trong n số trên mỗi vòng.

Mục tiêu: Chọn một số từ mỗi vòng sao cho tổng của chúng đúng bằng S.

Ràng buộc: m nhỏ (2 ≤ m ≤ 5), nhưng n lớn (1 ≤ n ≤ 10⁵), cần tối ưu.

2. Giải pháp Meet-in-the-Middle
Bài toán này có thể giải bằng Meet-in-the-Middle để giảm độ phức tạp từ O(n^m) xuống O(n^(m/2)):

Chia vòng khóa thành hai nhóm

Nếu m = 4, chia thành 2 nhóm: (vòng 1, vòng 2) và (vòng 3, vòng 4).

Nếu m = 5, chia thành 2 nhóm: (vòng 1, vòng 2, vòng 3) và (vòng 4, vòng 5).

Sinh tất cả tổng có thể từ mỗi nhóm

Duyệt tất cả cách chọn số từ nhóm thứ nhất, lưu vào unordered_map (đếm số lần xuất hiện).

Duyệt tất cả cách chọn số từ nhóm thứ hai, kiểm tra tổng S - tổng nhóm 2 có tồn tại trong nhóm 1 không.

Ghép hai nhóm để tìm tổng đúng bằng S

Với mỗi tổng T từ nhóm 1, tìm S - T trong nhóm 2 bằng unordered_map (O(1) tra cứu).

Nếu tìm thấy, cộng số cách chọn tương ứng vào kết quả.

3. Độ phức tạp
Sinh tất cả tổng có thể của mỗi nhóm: O(n^(m/2))

Tra cứu nhanh bằng unordered_map: O(1)

Tổng độ phức tạp: O(n^(m/2)), chấp nhận được khi m ≤ 5 và n ≤ 10⁵.

4. Kết luận
Meet-in-the-Middle giúp tối ưu thay vì thử tất cả tổ hợp.

unordered_map giúp tra cứu nhanh các tổng cần tìm.

Đây là chiến thuật hiệu quả khi m nhỏ nhưng n lớn.
