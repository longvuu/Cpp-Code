t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    d = {}
    for _ in range(k):
        b, c = map(int, input().split())
        if b in d:
            d[b] += c
        else:
            d[b] = c
    s = sorted(d.values(), reverse=True)
    ans = sum(s[:n])
    print(ans)