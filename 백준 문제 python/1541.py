# 반례 마이너스가 절대 나오지 않는다면?
import sys

splitByMinus = sys.stdin.readline().split("-")

res = 0

for i in range(len(splitByMinus)):
    currentSum = 0
    if "+" in splitByMinus[i]:
        for splits in map(int, splitByMinus[i].split("+")):
            currentSum += splits
    else:
        currentSum += int(splitByMinus[i])
    if i == 0:
        res += currentSum
    else:
        res -= currentSum

print(res)
