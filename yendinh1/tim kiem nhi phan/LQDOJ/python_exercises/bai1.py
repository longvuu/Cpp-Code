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

n = int(input())
if n <= 0:
    print("Nhập số nguyên dương")
else:
    print(solve(n))
