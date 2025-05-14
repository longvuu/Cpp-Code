def tong(numbers):
    t = 0
    for i in numbers:
        if i % 2 != 0: 
            t += i
    return t

n = int(input())
if n > 0:
    a = [int(input()) for _ in range(n)]
    print(tong(a))
else:
    print(0)
