Giải thích thuật toán
Bài toán yêu cầu tìm số nguyên dương nhỏ nhất 
𝑚
m sao cho 
𝑘
×
𝑚
k×m là một số chỉ chứa một chữ số lặp lại (ví dụ: 111, 222, 99999).

Ý tưởng chính
Một số có tất cả các chữ số giống nhau có thể biểu diễn dưới dạng 
𝑐
=
𝑝
×
𝑗
c=p×j, trong đó:

𝑝
p có dạng 1, 11, 111, 1111, ..., 111111111 (có tối đa 9 chữ số 1).

𝑗
j là một chữ số từ 1 đến 9 để tạo ra các số như 111, 222, ..., 999999999.

Nếu tồn tại 
𝑐
c chia hết cho 
𝑘
k, thì ta có thể tính 
𝑚
=
𝑐
𝑘
m= 
k
c
​
 .

Mục tiêu là tìm 
𝑚
m nhỏ nhất.

Chi tiết thuật toán
Sinh các số có chữ số giống nhau

Duyệt qua các số có dạng 
𝑝
=
1
,
11
,
111
,
…
,
111111111
p=1,11,111,…,111111111 bằng cách đặt:

𝑝
=
𝑝
×
10
+
1
p=p×10+1
Với mỗi 
𝑝
p, nhân với các số từ 9 đến 1 để tạo ra các số có chữ số giống nhau:

𝑐
=
𝑝
×
𝑗
c=p×j
Ví dụ:

𝑝
=
111
p=111, khi nhân với 2 → 
𝑐
=
222
c=222.

𝑝
=
11111
p=11111, khi nhân với 7 → 
𝑐
=
77777
c=77777.

Kiểm tra chia hết cho 
𝑘
k

Nếu 
𝑐
c chia hết cho 
𝑘
k, ta tìm được 
𝑚
m:

𝑚
=
𝑐
𝑘
m= 
k
c
​
 
So sánh với giá trị nhỏ nhất của 
𝑚
m đã tìm được để cập nhật kết quả.

Xuất kết quả

Do 
𝑚
m có thể rất lớn, nên ta chỉ cần in phần dư của 
𝑚
m khi chia cho 
10
9
+
7
10 
9
 +7.

