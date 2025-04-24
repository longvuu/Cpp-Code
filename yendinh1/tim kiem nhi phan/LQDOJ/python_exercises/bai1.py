def check(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def solve(n):
    if n <= 0:
        return 0
    a = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            a.append(i)
            if i != n // i:
                a.append(n // i)
    res = 0
    for i in a:
        if check(i):
            res += 1
    return res

n = int(input("Nhập số nguyên dương n: "))
if n <= 0:
    print("Vui lòng nhập số nguyên dương")
else:
    kq = solve(n)
    print(f"Số lượng ước của {n} là số nguyên tố: {kq}")
