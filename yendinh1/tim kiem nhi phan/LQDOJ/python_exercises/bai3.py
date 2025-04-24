def tong(numbers):
    t = 0
    for i in numbers:
        if i % 2 != 0: 
            t += i
    return t

print("Chương trình tính tổng các số lẻ trong danh sách A")
n = int(input("Nhập số phần tử của danh sách A: "))
if n <= 0:
    print("Số phần tử phải là số nguyên dương")
else:
    a = []
    print(f"Nhập {n} số nguyên:")
    for i in range(n):
        num = int(input(f"A[{i+1}] = "))
        a.append(num)
    odd_sum = tong(a)
    print(f"Tổng các số lẻ trong danh sách A: {odd_sum}")