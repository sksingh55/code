def lcs3(a, b, c):
    n = len(a)
    m = len(b)
    l = len(c)

    if 0 in (n, m, l):
        return 0

    E = [[[0] * (l + 1) for _ in range(m + 1)] for _ in range(n + 1)]

    for i in reversed(range(n + 1)):
        for j in reversed(range(m + 1)):
            for k in reversed(range(l + 1)):
                if i == n or j == m or k ==l:
                    E[i][j][k] = 0
                elif a[i] == b[j] == c[k]:
                    E[i][j][k] = 1 + E[i + 1][j + 1][k + 1]
                else:
                    E[i][j][k] = max(E[i + 1][j][k], E[i][j + 1][k], E[i][j][k + 1])

    return E[0][0][0]



n = int(input())
x = input().split()
a = [int(i) for i in x]

m = int(input())
x = input().split()
b = [int(i) for i in x]

l = int(input())
x = input().split()
c = [int(i) for i in x]

print(lcs3(a,b,c))