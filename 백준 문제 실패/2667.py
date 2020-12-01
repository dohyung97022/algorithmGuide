import sys

n = int(sys.stdin.readline())
a = []
for i in range(n):
    a.append(list(map(int, input())))
cnt = 0
apt = []

print(a)

houseCountArry = [0]
houseCountIdx = 0


def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= n:
        return False
    if a[x][y] == 1:
        a[x][y] = 0
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        houseCountArry[houseCountIdx] += 1
        return True
    return False


for xInt in range(n):
    for yInt in range(n):
        if dfs(xInt, yInt) == True:
            cnt += 1
            houseCountIdx += 1
            houseCountArry.append(0)

houseCountArry.pop()

print(cnt)
for houseAmount in sorted(houseCountArry):
    print(houseAmount)
