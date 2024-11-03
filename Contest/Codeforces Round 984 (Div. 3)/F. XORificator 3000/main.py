def up_xor(n):
    if n < 0:
        return 0
    mod = n % 4
    if mod == 0:
        return n
    elif mod == 1:
        return 1
    elif mod == 2:
        return n + 1
    else:
        return 0

t = int(input())
for _ in range(t):
    l, r, i, k = map(int, input().split())
    sh = 1 << i

    sum = up_xor(r) ^ up_xor(l - 1)

    start = (l - k + sh - 1) // sh
    end = (r - k) // sh

    if start > end:
        xor = 0
    else:
        num = end - start + 1
        sh_xor = up_xor(end) ^ up_xor(start - 1)
        xor = (sh_xor << i)
        if num % 2 == 1:
            xor ^= k
    ans = sum ^ xor
    print(ans)